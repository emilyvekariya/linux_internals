#include<stdio.h>
#include<pthread.h>



pthread_t tid1;
pthread_t tid2;

//pthread_attr_t my_attr;

void* thread1(void *arg){
printf("first thread is executing \n");
return NULL;
}

void* thread2(void *arg){
printf("second thread is executing \n");
return NULL;
}


int main(void){
//pthread_t *ptr
int ret = pthread_create(&tid1,NULL, thread1, NULL);
int ret2 = pthread_create(&tid2,NULL, thread2, NULL);


if(ret)
printf("THread1 is not created\n");
else
printf("THread1 is created\n");

if(ret2)
printf("THread2 is not created\n");
else
printf("THread2 is created\n");

getchar();
printf("end");
//sleep(2);
//pthread_join(tid1, NULL);
//pthread_join(tid2, NULL);
return 0;
}
