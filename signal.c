/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

bool printTuring;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  printTuring = true;
  alarm(1);
  // exit(1); //exit after printing
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(1); //Schedule a SIGALRM for 1 second
  while(true) { //busy wait for signal to be delivered
    if (printTuring) {
      printf("Turing was right!\n");
      printTuring = false;
    }
    sleep(1);
  }
  return 0; //never reached
}