#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h> 
#include <unistd.h>
#include <time.h>

// colors used
//#define RED   "\x1B[31m"
//#define GRN   "\x1B[32m"
//#define RESET "\x1B[0m"
#define SIZE 10  // size of array
sem_t s_read , s_write;  // semaphores used


int vector[SIZE]; //array of data
int freq = 10000; //10 miliseconds (given in microseconds)

void * read1(){
  int i = 0;
  sem_post(&s_write);  // enables write semaphore, used for initial condition
  while(i<SIZE){
    sem_wait(&s_read);  // waits for read semaphore
    char result = vector[i] ^ 0x20;  //calculates result = data XOR 0x20
    printf("thread %lu found    in %d\t\x1B[32m %c\x1B[0m\n",pthread_self(),i,result); // prints result
    ++i;
    sem_post(&s_write);  //enables write semaphore
  }
}

void * write1(){
  int i = 0;
  srand ( time(NULL) );  // initialize random seed
  while(i<SIZE){
    sem_wait(&s_write);  //waits for write semaphore
    usleep(freq);        //waits for time in microseconds

    int k = rand() % 256;  //generates random of 8 bits, 0-255
    vector[i] = k;        //adds the number into the array   
    printf("thread %lu created  in %d\t\x1B[31m%d\x1B[0m\n",pthread_self(),i,k);  //prints the written number
    ++i;
    sem_post(&s_read); // enables read semaphore
  }
}

int main(){
  int status;
  pthread_t tr, tw;  // creates thread read and thread write
  // assign tasks to threads
  pthread_create(&tr,NULL,read1,NULL);
  pthread_create(&tw,NULL,write1,NULL);
  // waits for the threads to terminate
  pthread_join(tr,NULL);
  pthread_join(tw,NULL);
  return 0;
}
