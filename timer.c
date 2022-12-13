#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int turingFlag = 0;
int numAlarm = 0;

time_t start, stop;

void alarmHandler(int signum)
{ //signal handler
  printf("Hello World!\n");
  sleep(2);
  turingFlag = 1;
  numAlarm++;
}

void sigintHandler(int signum)
{
  int timeTotal;
  stop = time(NULL);
  timeTotal = stop - start;
  printf("The number of alarms is %d\n", numAlarm);
  printf("Time elasped %ds\n", timeTotal);
  exit(1);
}

int main(int argc, char * argv[])
{
  signal(SIGALRM, alarmHandler); //register handler to handle SIGALRM
  signal(SIGINT, sigintHandler);
  start = time(NULL);
  while(1){
    turingFlag = 0;
    alarm(2);
    while(!turingFlag);
    printf("Turing was right!\n");
  }
  return 0;
}