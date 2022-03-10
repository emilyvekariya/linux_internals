#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

void callback1(void){
	printf("callback1 func called\n");
}
void callback2(void){
	printf("callback2 func called\n");
}
void callback3(void){
	printf("callback3 func called\n");
}


int main(void){

printf("registering callback 1\n");
atexit(callback1);
printf("registering callback 2\n");
atexit(callback2);
printf("registering callback 3\n");
atexit(callback3);
printf("main()...exiting now");

//_exit(0);
exit(0);
}


