#include<stdio.h>
#include<pthread.h>

//pthread_attr_t my_attr;

void* thread1(void *arg){
char *s=(char *)arg;
printf("%s\n",s);
return 0;
}



int main(int argc,char *argv[]){
pthread_t t1;
void *res;
int s;

int ret = pthread_create(&t1,NULL, thread1, "hello world");

printf("end\n");
sleep(3);
//pthread_join(tid1, NULL);
//pthread_join(tid2, NULL);
return 0;
}
