#include <stdio.h> 
#include <unistd.h> 

#define READ 0 
#define WRITE 1 
#define MAX_STRING_lEN 80


int main() { 
  int fd[2]; 
  pid_t pid; 
  
  pipe(fd); 
  pid = fork(); 
  if (pid >0) {      //pai 
    char a[MAX_STRING_lEN];
    char b[MAX_STRING_lEN];

    printf("PARENT:\n"); 
    printf("x y ? "); scanf("%s %s", &a, &b); 
    close(fd[READ]); 
    write(fd[WRITE], &a, sizeof(int)); 
    write(fd[WRITE], &b, sizeof(int)); 
    close(fd[WRITE]); 
  } 
  else {             //filho 
    char x[MAX_STRING_lEN];
    char y[MAX_STRING_lEN]; 

    close(fd[WRITE]); 
    read(fd[READ], &x, sizeof(int));
    read(fd[READ], &y, sizeof(int));
    printf("SON:\n");
    printf("x + y = %d\n", atoi(x)+atoi(y)); 
    close(fd[READ]); 
  } 
  return 0; 
} 

