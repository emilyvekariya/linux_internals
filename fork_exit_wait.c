#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main(){

pid_t pid;

pid=fork();

if(pid<0){
	fprintf(stderr,"Fork failed");
	exit(-1);
}
if(pid==0){
	execl("/bin/ls","ls",NULL);
	exit(0);
}
else{
	wait(NULL);
 	printf("i am parent pid %d\n",getpid());
 	exit(0);
}
}
