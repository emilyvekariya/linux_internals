#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/mman.h>

void *proc(void* param){
	sleep(3);
	return 0;
}

int main(int argc,char *argv[]){
	pthread_attr_t attr;
	pthread_t id;
	int err,info;

	pthread_attr_init(&attr);
	pthread_attr_getinheritsched(&attr,&info);
	switch(info){
		case PTHREAD_INHERIT_SCHED:
			printf("\nSCHED\n");
			break;
		case PTHREAD_EXPLICIT_SCHED:
			printf("\nEXPLICIT\n");
			break;
	}
	pthread_attr_setinheritsched(&attr,PTHREAD_EXPLICIT_SCHED);
	pthread_attr_getinheritsched(&attr,&info);
	switch(info){
		case PTHREAD_INHERIT_SCHED:
			printf("\nSCHED\n");
			break;
		case PTHREAD_EXPLICIT_SCHED:
			printf("\nEXPLICIT\n");
			break;
	}
	printf("process creating thread whose sched policy is given by thread task proc\n");

	pthread_create(&id,&attr,proc,NULL);
	pthread_join(id,NULL);
	return 0;
}
