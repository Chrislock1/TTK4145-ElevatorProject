// gcc 4.7.2 +
// gcc -std=gnu99 -Wall -g -o helloworld_c helloworld_c.c -lpthread

#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mut;

int i = 0;
int val = 1000000000;

void* threadAdder(){
    for(int x = 0; x< val; ++x){
	pthread_mutex_lock(&mut);	// Forskjell på lock og trylock?
	++i;
	pthread_mutex_unlock(&mut);
  }
  return NULL;
}

void* threadSubtractor(){
    for(int y = 0; y< val; ++y){
	pthread_mutex_lock(&mut);
	--i;
	pthread_mutex_unlock(&mut);
	
  }
  return NULL;
}



int main(){
    if(pthread_mutex_init(&mut, NULL) != 0){
	printf("Mutex init failed \n");
	return 1;
    }

    pthread_t adder;
    pthread_t subtractor;

    pthread_create(&adder, NULL, threadAdder, NULL);
    pthread_create(&subtractor, NULL, threadSubtractor, NULL);
    
    pthread_join(adder, NULL);		//Hva gjør dette?
    pthread_join(subtractor, NULL);

    pthread_mutex_destroy(&mut);
    printf("i = %i \n", i);

    return 0;
    
}
