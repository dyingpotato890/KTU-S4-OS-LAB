#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void main(){
	pid_t pid = fork();
	
	if (pid < 0)
		printf("Creation Of Child Process Failed\n");
	else if(pid == 0){
		printf("Child Process ID (Executing ls -l): %d", getpid());
		
		char *args[] = {"ls", "-l", NULL};
		execvp(args[0], args);

		perror("execvp failed");
		exit(EXIT_FAILURE);
	}
	else{
		printf("Parent Process (ID: %d) waiting for child process to finish executing\n", getppid());
		wait(NULL);
		printf("Child Process Completed!\n");
	}
}
