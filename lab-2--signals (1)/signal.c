/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int wait = 0; 

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  wait= 1;
  //exit after printing
}

int main(int argc, char * argv[])
{
 while(8){
    signal(SIGALRM,handler); //register handler to handle SIGALRM
    alarm(1); //Schedule a SIGALRM for 1 second
    while(!wait); //busy wait for signal to be delivered
    printf("Turing was right!\n");
    wait = 0;
  }
  return 0;
}