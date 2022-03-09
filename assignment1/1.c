#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
   int f1,f2,len,total;

   char buff_copy[100];
   char new[100];
   f1 = open("read.txt",O_RDONLY,777);
   f2 = open("new.txt",O_CREAT | O_RDWR,777);
   
   read(f1,buff_copy,100);

   total = lseek(f1,0,SEEK_END);
   printf("Total = %d\n",total);
   write(f2,buff_copy,total);
   lseek(f2,0,SEEK_SET);
   read(f2,new,total);
   printf("Data: %s\n",new);
   close(f1);
   close(f2);
   return 0;
}
