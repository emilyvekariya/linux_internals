#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[]){

int i;
printf("filename = %s\n",argv[0]);
printf("total number of arguments %d\n",argc);
printf("argument passed\n");
for(i=0;i<argc;i++){
	printf("%s " ,argv[i]);
}
printf("\n");
}
