// PROGRAMA prob2a.c 
#include <stdio.h> 
#include <signal.h> 
#include <unistd.h> 
#include <stdlib.h> 

int increment = 1;

void handler(int signo) 
{ 
  if(signo == SIGUSR1){
  increment = 1;
  }
  
  if(signo == SIGUSR2){
  increment = -1;
  }
}

int main(void) 
{ 
 int value = 100;
 
 if (signal(SIGUSR1,handler) < 0) 
 { 
       fprintf(stderr,"Unable to install SIGUSR1 handler\n"); 
       exit(1); 
 }
 if (signal(SIGUSR2,handler) < 0) 
 { 
       fprintf(stderr,"Unable to install SIGUSR2 handler\n"); 
       exit(1); 
 }
 while(1){
    printf("Value = %d\n", value);
    value += increment;
    sleep(1);
} 
 return(0); 
}
