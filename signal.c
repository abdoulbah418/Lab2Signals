/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int turingFlag = 0;

void alarmHandler(int signum)
{ //signal handler
  printf("Hello World!\n");
  sleep(1);
  turingFlag = 1;
}


int main(int argc, char * argv[])
{
  signal(SIGALRM, alarmHandler); //register handler to handle SIGALRM
  while(1) {
    turingFlag = 0;
    alarm(2);
    while(!turingFlag);
    printf("Turing was right!\n");
  }
  return 0;
}
