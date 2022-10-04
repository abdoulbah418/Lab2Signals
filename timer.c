/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

bool printTuring;
clock_t time_start;
int alarm_count;

void sigalrmHandler(int signum)
{ //signal handler
  printf("Hello World!\n");
  printTuring = true;
  alarm_count += 1;
  alarm(1);
  // exit(1); //exit after printing
}

void sigintHandler(int signum)
{ //signal handler
  printf("\nTime Elasped: %.2f seconds\n", (float)(clock() - time_start)/100);
  printf("Alarm Count: %d\n", alarm_count);
  exit(1);
}

int main(int argc, char * argv[])
{
  time_start = clock();
  signal(SIGALRM,sigalrmHandler); //register handler to handle SIGALRM
  signal(SIGINT,sigintHandler); //register handler to handle SIGINT
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