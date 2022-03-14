#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

void *printhello(void *threadid){
	printf("\nHello World!\n");
	while(1);
}

int main()
{ 
   pthread_t thread;

   int t=0;
   printf("\nCreating thread\n");
   int ret = pthread_create(&thread,NULL,printhello,NULL);
   printf("Thread id : %u\n",thread);
   sleep(6);
   t = pthread_cancel(thread);
   if(t == 0)
   {
     printf("\nThread cancelled\n");
     printf("Thread id: %u\n",thread);
   }

  
   return 0;
}
