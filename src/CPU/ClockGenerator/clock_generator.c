#include "../../../include/clock_generator.h"
#include "../../../include/global.h"


#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h> 
#include <unistd.h>
#include <time.h>


void * clock_generator(){
  while(1){
    usleep(1000000);
    clock_value = !clock_value;
  }
  return NULL;
}