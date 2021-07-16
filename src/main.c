#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h> 
#include <unistd.h>
#include <time.h>

#include "../include/global.h"
#include "../include/clock_generator.h"

  
int clock_value = 0;




int main(){
  pthread_t thrd_clk, tw;
  pthread_create(&thrd_clk,NULL,clock_generator,NULL);

  
  
  int x = 0;
  while(x < 5){
    x++;
    printf("number: %d\n",x);
  }



}