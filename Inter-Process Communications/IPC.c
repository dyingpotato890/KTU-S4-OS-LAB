#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

void main(){
    key_t key;
    char *ptr, *shm;

    key = ftok("readfile.txt", 'R');

    int shmid = shmget(key, SHM_SIZE , IPC_CREAT | 0666);

    shm = shmat(shmid, NULL, 0);

    ptr = shm;
	sprintf(ptr, "Shared Memory Content");
	printf("Data Written To Shared Memory\n");

    shm = shmat(shmid, NULL, 0);
    ptr = shm;
    while( *ptr != '\0'){
        printf("%c", *ptr);
        ptr++;
    }

    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);
    printf("Shared Memory Destroyed\n");
}