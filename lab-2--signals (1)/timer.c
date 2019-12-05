#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

/*Program a new program timer.c that after exiting (via CTRL-C), will print out the total time the
program was executing in seconds. To accomplish this task, you will need to register a second signal
handler for the SIGINT signal, the signal that is delivered when CTRL-C is pressed. Conceptually,
your program will request a SIGALRM signal to occur every second, tracking the number of alarms
delivered, and when the program exits via CTRL-C, it will print how many alarms occurred, or the
number of seconds it was executed.*/


int seconds =0; 
int wait = 0; 
void other_handler(int signum){
  printf("\nTime elapsed for executing: %d seconds\n", seconds);
  exit(1);
}
void handler(int signum){ 
  wait= 1;
}
int main(int argc, char * argv[])
{
  signal(SIGINT,other_handler);
 while(8){
    signal(SIGALRM,handler); 
    alarm(1); //Schedule a SIGALRM for 1 second
    while(!wait); 
    seconds++;
    wait = 0;
  }
  return 0;
}