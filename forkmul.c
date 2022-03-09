#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void){

pid_t pid,pid1;
printf("current process pid = %d\n",getpid());

pid=fork();// parent suspended

if(pid){
  printf("parent process pid= %d\n", getpid());
}
else{	
	printf("child process pid= %d\n", getpid());
	pid1=fork();// parent suspended

	if(pid1){
	  printf("parent process pid1= %d\n", getpid());
	}
	else{
	  printf("child process pid1= %d\n", getpid());
	}
}
exit(0);
return 0;
}
