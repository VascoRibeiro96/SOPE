#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main (void) {
    pid_t pid, pid2;

    pid = fork();

    if (pid == 0) {
        pid2 = fork();

        if (pid2 == 0) { //processo do neto
            printf("Hello ");
        }
        else {
		wait(NULL);   //processo do filho         
		printf("my ");   
        }
    }
    else { // processo do pai
        wait(NULL);
	printf("friends!\n");
    }

    return 0;
}
