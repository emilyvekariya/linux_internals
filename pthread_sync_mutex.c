#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>

int sharedvar=5;

pthread_mutex_t my_mutex;

void *thread_inc(void *arg){
	pthread_mutex_lock(&my_mutex);
	sharedvar++;
	pthread_mutex_unlock(&my_mutex);
	printf("after inreament= %d\n",sharedvar);
}

void *thread_dec(void *arg){
	pthread_mutex_lock(&my_mutex);
	sharedvar--;
	pthread_mutex_unlock(&my_mutex);
	printf("after decreament= %d\n",sharedvar);
}

int main(){
	pthread_t thread1,thread2;

	pthread_mutex_init(&my_mutex,NULL);

	pthread_create(&thread1,NULL,thread_inc,NULL);
	pthread_create(&thread2,NULL,thread_dec,NULL);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	printf("shared var= %d\n",sharedvar);
	return 0;
}
