#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>



int main(){



int fd, len;
int x;
char write_buf[60]="HI! ITS linux read write code!!";
char buf[300];



fd= open("abc.txt",O_CREAT | O_RDWR,0777);
printf("%d\n",fd);



len=write(fd,write_buf,60);
printf("return value from write operation: %d\n",len);




lseek(fd,0,SEEK_SET);

if(fd<0)
printf("FIle is not opened or created\n");



read(fd,buf,len);
printf("data from buffer= %s\n",buf);



close(fd);
return 0;



}
