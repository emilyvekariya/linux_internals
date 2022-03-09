#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
int main()
{
int fd;
char buffer[100];
fd= open("read.txt",O_RDONLY);



//lseek(fd,0,SEEK_SET);
//read(fd,buffer,300);
//printf("data from buffer= %s\n",buffer);



//lseek(fd,-5,SEEK_END);
//read(fd,buffer,300);
//printf("data from buffer= %s\n",buffer);
lseek(fd,3,SEEK_SET);
lseek(fd,1,SEEK_CUR);
if(fd<0)
printf("FIle is not opened or created\n");



read(fd,buffer,300);
printf("data from buffer= %s\n",buffer);



close(fd);
return 0;
}
