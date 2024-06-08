#include <stdio.h>
#include <string.h>

int nb, np;

void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    memset(allocation, -1, sizeof(allocation));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

	 printf("\n---------------- FIRST FIT ALGORITHM ----------------");
    printf("\nProcess No.\t    Process Size\t    Block no.");
    printf("\n-----------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf(" %d\t\t      %d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("      \t%d", allocation[i] + 1);
        else
            printf("  Not Allocated");
        printf("\n");
    }
	printf("-----------------------------------------------------\n");
	 
    printf("\nFree Blocks\n");
    for (int i = 0; i < m; i++) 
    	printf("%d -> ",blockSize[i]);
	printf("NULL\n");
}

int main() {    
    printf("Enter The Number Of Blocks: ");
    scanf("%d", &nb);
    printf("Enter The Number Of Processes: ");
    scanf("%d", &np);
    
    int blockSize[nb], processSize[np];
    
    printf("\n");
    for (int i = 1; i <= nb; i++){
    	printf("Enter The Size Of Block %d: ", i);
    	scanf("%d", &(blockSize[i-1]));
    }
    printf("\n");
    for (int i = 1; i <= np; i++){
    	printf("Enter The Size Of Process %d: ", i);
    	scanf("%d", &(processSize[i-1]));
    }
    
    firstFit(blockSize, nb, processSize, np);
    return 0;
}
