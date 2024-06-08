#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main(){
	pid_t cnum = fork();
	
	if (cnum < 0)
		printf("Child Creation Failed!\n");
	else if (cnum == 0)
		printf("Process ID Of Child Proces = %d\n", getpid());
	else
		printf("Process ID Of Parent Proces = %d\n", getppid());
}
