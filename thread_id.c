#include<stdio.h>
#include<pthread.h>

pthread_t tid;

void* thread_func(void *arg){

pid_t pid;
pthread_t tid;
pid=getpid();
tid=pthread_self();
printf("pid= %u & tid= %u\n",(unsigned int)pid,(unsigned int)tid);
return 0;
}



int main(int argc,char *argv[]){

int err;

err= pthread_create(&tid,NULL, thread_func, NULL);

if(err !=0)
	printf("can't create thread: %s\n",strerror(err));

while(1);
exit(0);
}
