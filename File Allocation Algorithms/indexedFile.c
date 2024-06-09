#include <stdio.h>
#include <stdlib.h>

int n, blocks[100], index, length, count = 0, index_block[100];

void indexed(){
    char c = 'y';

    while (c == 'y' || c == 'Y'){
        count = 0;
        printf("Enter The File Index Block Number: ");
        scanf("%d", &index);
        if (index >= n || index < 0){
            printf("Invalid Index Block Number! Please Enter a Valid Index.\n");
            continue;
        }

        if (blocks[index] == 1)
            printf("Index block already allocated! No allocation possible.\n");
        else{
            printf("Enter The File Length: ");
            scanf("%d", &length);

            blocks[index] = 1;

            int start = 0;
            for (int i = start; i < n && count < length; i++){
                if (blocks[i] == 0){
                    blocks[i] = 1;
                    index_block[count] = i;
                    count++;
                }
            }

            if (count < length){
                printf("Insufficient Storage! No Allocation.\n");
                blocks[index] = 0;
                for (int i = start; i < n && i < start + count; i++)
                    blocks[i] = 0;
            }
            else{
                printf("File Allocated to Disk With Index Block %d\n", index);
                for (int i = 0; i < count; i++)
                    printf("%d->%d\n", index, index_block[i]);
            }
        }
        printf("\nAre There More Files? (y/n): ");
        scanf(" %c", &c);
    }
}

int main(void){
    printf("Enter the Number of Free Blocks: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        blocks[i] = 0;

    indexed();
    return 0;
}