#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main(void){

pid_t pid;
if(pid==0){
 sleep(5);
 printf("I am child with delay of 5 sec and my child pid is %d\n",pid);
}
else{
 int pid1;
 printf("i am parent pid %d\n",getpid());
 pid1=wait(0);

printf("parent saying child %d existed/ terminated normally\n",pid1);
printf("i am patent process pro pid %d\n",getpid());
}
}
