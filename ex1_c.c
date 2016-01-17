// gcc 4.7.2 +
// gcc -std=gnu99 -Wall -g -o helloworld_c helloworld_c.c -lpthread

#include <pthread.h>
#include <stdio.h>

int i = 0;


// Note the return type: void*
void* threadAdder(){
    for(int x = 0; x< 1000000; ++x){
	++i;
  }
}

void* threadSubtractor(){
    for(int y = 0; y< 1000000; ++y){
	--i;
	
  }
}



int main(){
    pthread_t adder;
    pthread_t subtractor;

    pthread_create(&adder, NULL, threadAdder, NULL);
    pthread_create(&subtractor, NULL, threadSubtractor, NULL);
    
    pthread_join(adder, NULL);
    pthread_join(subtractor, NULL);

    printf("i = %i \n", i);

    return 0;
    
}
