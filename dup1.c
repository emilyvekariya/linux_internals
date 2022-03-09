#include<stdio.h>
#include<fcntl.h>

int main(){
int fd1,fd2,fd3,fd4;
fd1=open("linux.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777); //3
fd2=open("linuxnew.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777); //4
printf("fd1= %d\n",fd1);
printf("fd2= %d\n",fd2);
fd3=dup(fd1);
printf("fd3= %d\n",fd3);// 3,4,5

fd4=dup2(fd1,4); //generating descreptor our own reqd value....44
printf("fd4 is our defined dup of fd1= %d\n",fd4);

close(fd1);
close(fd2);
close(fd3);
}
