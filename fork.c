#include<stdio.h>
#include<unistd.h>

int main(void){

int pid;

//fork();
//fork();
pid=fork();
if(pid==0){
  printf("child process\n");
}
else{
  printf("parent process\n");
}
while(1);
return 0;
}
