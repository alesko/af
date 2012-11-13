#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 10

void* print_msg_func(void *ptr);

pthread_mutex_t gmutex1 = PTHREAD_MUTEX_INITIALIZER;
int gcounter;


int c_main()
{

   gcounter = 0;
   pthread_t thread[NTHREADS];
   char* msg = "Messange from thread";
   //char* msg1 = "Messange from thread 1";

   int ret[NTHREADS];
   int i,j;
   for(i=0; i<NTHREADS; i++)
   {
	   ret[i] = pthread_create(&thread[i], NULL, print_msg_func, msg);
   }
   //ret1 = pthread_create(&thread1, NULL, print_msg_func, (void*) msg1);

   for(j=0; j<NTHREADS; j++)
   {
	   pthread_join(thread[j], NULL);
   }
   
   //pthread_join(thread1, NULL);
   for(j=0; j<NTHREADS; j++)
   {
	   printf("Thread %ld returns: %d\n",thread[j], ret[j]);
   }
   //exit(0);
   return 1;

}

void* print_msg_func(void *ptr)
{
   char* msg;
   msg = (char*) ptr;
   
   printf("Thread number %ld\n", pthread_self());
   pthread_mutex_lock( &gmutex1 );
   gcounter++;
   printf("%s: counter is: %d\n",msg,gcounter);
   pthread_mutex_unlock( &gmutex1 );
}