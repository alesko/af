#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* print_msg_func(void *ptr);

void main()
{

   pthread_t thread0, thread1;
   char* msg0 = "Messange from thread 0";
   char* msg1 = "Messange from thread 1";

   int ret0, ret1;

   ret0 = pthread_create(&thread0, NULL, print_msg_func, (void*) msg0);
   ret1 = pthread_create(&thread1, NULL, print_msg_func, (void*) msg1);

   pthread_join(thread0, NULL);
   pthread_join(thread1, NULL);
   printf("Thread one returns: %d\n", ret0);
   printf("Thread one returns: %d\n", ret1);
   exit(0);

}

void* print_msg_func(void *ptr)
{
   char* msg;
   msg = (char*) ptr;
   printf("%s \n",msg);
}