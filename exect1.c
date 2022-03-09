#include<stdio.h>
#include<unistd.h>

int main(){

printf("i am going to execute ls progrm\n");

//execl("/bin/ls","ls","-lh",0);

execl("/home/emily/linux/vfork.c","a.out",0);

printf("I executed ls program");
}
