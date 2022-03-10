#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main(void){

int pid;
int status;

printf("parent= %d\n",getpid());

pid=fork();
if(pid==0){
	printf("child= %d\n",getpid());
	sleep(2);
	exit(0);
}

printf("parent reporting exit of child whose pid %d\n",waitpid(pid,&status,0));
}
