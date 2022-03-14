#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<errno.h>
#include<bits/types.h>

	int errno;

void * process(void *arg){

	pthread_detach(pthread_self());
	printf("sleeping 2 sec\n");
	sleep(2);
	printf("slept 2 sec\n");
}

int main(void){
	pthread_t t_id;
	errno=pthread_create(&t_id,NULL,process,NULL);

	if(errno)
		perror("pthread created");

	pthread_exit(NULL);
}
