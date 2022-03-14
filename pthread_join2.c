#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>

//pthread_attr_t my_attr;

void* thread1(void *arg){
char *s=(char *)arg;
printf("%s\n",s);
sleep(5);
return (void*)strlen(s);
return 0;
}



int main(int argc,char *argv[]){
pthread_t t1;
void *res;
int s;

int ret = pthread_create(&t1,NULL, thread1, "hello world");

printf("Mesaage from main()\n");
sleep(3);

pthread_join(t1,&res);

printf("thread return %ld\n",(long) res);
exit(0);
}
