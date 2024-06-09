#include <stdio.h>

int n, b, l, k, block[100];

void contigious(){
    int flag;
    char c = 'y';

    while (c == 'y' || c == 'Y'){
        flag = 0;
        printf("Enter The File Starting Block: ");
        scanf("%d", &b);
        printf("Enter The File Length: ");
        scanf("%d", &l);

        if (l > n)
            printf("File Cannot Be Allocated! Insufficient Space In The Disk.\n");

        else{
            k = 0;

            for (int j = b; j < b+l; j++){   
                if (block[j] == 1){
                    flag = 1;
                    break;
                }
            }

            if (flag == 0){   
                printf("File Allocated to Blocks: ");
                for (int j = b; j < b+l; j++){
                    block[j] = 1;
                    printf("%d ", j);
                }
                printf("\n");
            }
            
            else
                printf("File cannot be allocated! Some blocks are already allocated.\n");
        }
        printf("\nAre There More Files? (y/n): ");
        scanf(" %c", &c);
    }
}

int main(void){    
    printf("Enter the Number of Blocks: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        block[i] = 0;

    contigious();
}