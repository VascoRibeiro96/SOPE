// PROGRAMA p01c.c 
#include <stdio.h> 
#include <signal.h> 
#include <unistd.h> 
#include <stdlib.h> 
void sigint_handler(int signo) 
{ 
  printf("In SIGINT handler ...\n"); 
} 
int main(void) 
{ 

  struct sigaction action;
  action.sa_handler = sigint_handler;

  int mysleep = 30;
  if (sigaction(SIGINT,&action,NULL) < 0) 
  { 
    fprintf(stderr,"Unable to install SIGINT handler\n"); 
    exit(1); 
  }
  printf("Sleeping for 30 seconds ...\n");
  while(mysleep >0){
  mysleep = sleep(mysleep);
  }
  printf("Waking up ...\n"); 
  exit(0); 
}
