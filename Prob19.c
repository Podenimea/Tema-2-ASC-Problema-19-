#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
void *function1();
void *function2();
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
double x;
int main()
{
	scanf("%lf",&x);
 	int rc1, rc2;
 	
 	pthread_t thread1, thread2;
 	//creare thread-uri
 	if( (rc1=pthread_create( &thread1, NULL, &function1, NULL)) )
 	{
 		printf("Eroare de creare thread-uri! %d \n", rc1);
 	}	
 	if( (rc2=pthread_create( &thread2, NULL, &function2, NULL)) )
 	{
 		printf("Eroare de creare thread-uri! %d\n", rc2);
 	}
 	pthread_join( thread1, NULL);
 	pthread_join( thread2, NULL);
 	printf("Rezultat:\n%lf\n",x);
	printf("Sfarsit program!\n");
	exit(EXIT_SUCCESS);
}
void *function1(){
	double fx;
	double fdev;
	double rap;
	int i,n=257;
	for(i=1;i<=n;i++){
		pthread_mutex_lock( &mutex1 );
		fx=x*x+2*x-3;
		fdev=2*x+2;
		rap=fx/fdev;
		x=x-rap;
		printf("Thread 1:\n%lf\n",x);
		pthread_mutex_unlock( &mutex1 );
		//sleep(1);
	}
}
void *function2(){
	double fx;
	double fdev;
	
	double rap;
	int i,n=257;
	for(i=1;i<=n;i++){
		pthread_mutex_lock( &mutex1 );
		fx=x*x+2*x-3;
		fdev=2*x+2;
		rap=fx/fdev;
		x=x-rap;
		printf("Thread 2:\n%lf\n",x);
		pthread_mutex_unlock( &mutex1 );
		//sleep(1);
	}
}