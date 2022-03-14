#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<pthread.h>

pthread_t tid;
int fd;

void* thread_func(void *p){

char* str,buff[100];
pid_t pid;
int n;
str=(char *)p;
pthread_t tid;
pid=getpid();

printf("%s: started now: \t for process %d\n\n",str,pid);

do{
n=read(fd,buff,100);
printf("%s: \t READ: \t %d \n\n",str,pid);
printf(".....................");
write(1,buff,n);

printf(".....................");
sleep(3);
}while(n);

printf("%s: \t finished: \t for precess %d \n\n",str,pid);

return 0;
}


int fd;
int main(){

pthread_t t1,t2;
fd=open("/etc/passwd",O_RDONLY);
printf("file opened with fd: %d\n",fd);

pthread_create(&t1,NULL,thread_func,"thread one");
pthread_create(&t2,NULL,thread_func,"thread one");

pthread_join(t1,NULL);
pthread_join(t2,NULL);
}
