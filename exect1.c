#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main(void){

int pid;
pid=fork();
int option,stst;

while(1){
printf("enter 1 to exec ls program in child process\n");
scanf("%d",&option);
if(!option){
	exit(0);
}
printf("\n");
if(fork()==0){
	execl("/bin/ls","ls","-lh",0);
	exit(0);
}

return 0;
}





/*
printf("i am going to execute ls progrm\n");

execl("/bin/ls","ls","-lh",0);

//execl("/home/emily/linux/vfork.c","a.out",0);

printf("I executed ls program");
}*/
