#include<stdio.h>
#include<pthread.h>



pthread_t tid;

//pthread_attr_t my_attr;

void* thread1(void *arg){
printf("newly created thread is executing \n");
return NULL;
}



int main(void){
//pthread_t *ptr
int ret = pthread_create(&tid,NULL, thread1, NULL);



if(ret)
printf("THread is not created\n");
else
printf("THread is created\n");



//sleep(2);
pthread_join(tid, NULL);
return 0;
}
