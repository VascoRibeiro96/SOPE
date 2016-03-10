//Processo pai espera pelo filho

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void) { 
 pid_t pid;

 pid = fork();


if(pid > 0){      //processo pai espera que filho termine
 wait(NULL);
 printf("world!\n");
 return 0;
}

if(pid == 0) { //processo filho
 printf("Hello ");
 return 0;
}


} 
