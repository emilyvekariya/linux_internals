#include<unistd.h>
#include<errno.h>
#include<bits/types.h>
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<sys/types.h>
#define NUM_THREADS 3

int i=0;
void *myfun(void *null){
	i++;
	int result=0;
	result=result+i*1000;
	printf("result= %d\n",result);

	pthread_exit(NULL);
}

int main(int argc, char *argv[]){
	pthread_t thread[NUM_THREADS];
	pthread_attr_t attr;

	int rc,t,status,detach_state;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);

	for(t=0;t<NUM_THREADS;t++){
		printf("creating thread %d\n",t);
		pthread_create(&thread[t],&attr,myfun,NULL);
	}

	pthread_attr_getdetachstate(&attr,detach_state);
	printf("\ndetach state: %d\n",(int *)detach_state);

	printf("\nexiting from main thread\n");
	pthread_exit(NULL);

}
