#include<unistd.h>
#include<errno.h>
#include<bits/types.h>
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<sys/types.h>

static pthread_spinlock_t spinlock;
volatile int slock;

void *spinlockThread(void *i){
	int rc=0;
	int count=0;
	printf("entered thread %d ,getting spin lock\n",(int *)i);

	rc=pthread_spin_lock(&slock);

	printf("%d thread unlock the spin lock\n",(int *)i);
	rc=pthread_spin_unlock(&slock);

	printf("%d thread completed\n",(int *)i);
	return NULL;	
}

int main(){
	int rc=0;
	pthread_t pthread1;

	if(pthread_spin_init(&slock,PTHREAD_PROCESS_PRIVATE)!=0)
		perror("init");
		printf("main get spin lock\n");	
		rc=pthread_spin_lock(&slock);

		printf("main create spin lock\n");	
		pthread_create(&pthread1,NULL,spinlockThread,(int *)1);

		printf("main wait a bit holding the spin lock\n");
		sleep(5);
		
		printf("now unlock the spinlock\n");
		rc=pthread_spin_unlock(&slock);

		if(rc==0){
			printf("\nmain thread successfully unlock\n");
		}
		else{
			printf("\nmain thread unsuccessfully unlock\n");
		}

		printf("main wait for the thread to end\n");
		pthread_join(pthread1,NULL);
		printf("Main complete\n");	
return 0;
	
}
