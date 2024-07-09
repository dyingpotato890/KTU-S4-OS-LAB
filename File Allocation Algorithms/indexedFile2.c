#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct block{
    int blocks[20];
    struct block *next;
};

struct file{
    char name[10];
    int length;
    struct block *indexBlock;
    int noOfBlocks;
    struct file *next;
};

struct file *head = NULL;
int nf;

void DisplayAllocatedBlocks(struct block* indexBlock){
    struct block* temp = indexBlock;
    while(temp != NULL){
        for(int i = 0; i < 20; i++){
            if (temp -> blocks[i] == -1){
                break;
            }
            printf("%d, ", temp -> blocks[i]);
        }
        temp = temp -> next;
    }
    printf("\n");
}

void Display(){
    while(head != NULL){
        printf("\nFILE NAME: %s\n", head -> name);
        printf("FILE SIZE: %d\n", head -> length);
        printf("NUMBER OF INDEX BLOCKS: %d\n", head -> noOfBlocks);
        printf("ALLOCATED BLOCKS: ");
        DisplayAllocatedBlocks(head -> indexBlock);
        head = head -> next;
    }
}

int checkAvailability(int block){
    struct file* temp = head;
    while(temp != NULL){
        struct block *temp2 = temp -> indexBlock;
        while(temp2 != NULL){
            for (int x = 0; x < 20; x++){
                if (temp2 -> blocks[x] == block) return 0;
            }
            temp2 = temp2 -> next;
        }
        temp = temp -> next;
    }
    return 1;
}

void allocateBlocks(struct file *newFile){
    struct block *temp = newFile -> indexBlock;
    int currentBlock = temp -> blocks[0];

    int j = 1;

    for (int i = 1; i < newFile -> length; i++){
        int flag = 0;
        while(flag == 0){
            currentBlock++;
            flag = checkAvailability(currentBlock);
            if (flag == 1){
                if (j < 20){
                    temp -> blocks[j] = currentBlock;
                    j++;
                }
                else{
                    j = 0;
                    struct block *extend = (struct block*)malloc(sizeof(struct block));
                    memset(extend -> blocks, -1, sizeof(extend -> blocks));
                    temp -> next = extend;
                    temp = temp -> next;
                    newFile -> noOfBlocks += 1;
                    temp -> blocks[j] = currentBlock;
                    j++;
                }
            }
        }
    }
    temp -> next = NULL;
}

void main(){
    printf("Enter The Number Of Files: ");
    scanf("%d", &nf);

    struct file* temp = head;
    for (int z = 0; z < nf; z++){
        struct file *newFile = (struct file*)malloc(sizeof(struct file));

        printf("\nEnter The Name Of The File: ");
        scanf("%s", &(newFile -> name));
        printf("Enter The Length For The File: ");
        scanf("%d", &(newFile -> length));
        newFile -> noOfBlocks = 0;

        int flag = 0;
        while (flag == 0){
            int index;
            printf("Enter The First Block Index: ");
            scanf("%d", &index);

            flag = checkAvailability(index);

            if (flag == 0){
                printf("Block Already Assigned.\n");
                continue;
            }
            else{
                newFile -> indexBlock = (struct block*)malloc(sizeof(struct block));
                memset(newFile -> indexBlock-> blocks, -1, sizeof(newFile -> indexBlock -> blocks));
                newFile -> indexBlock -> blocks[0] = index;
                newFile -> noOfBlocks += 1;
            }
        }
        allocateBlocks(newFile);

        if (head == NULL){
            head = temp = newFile;
        }
        else{
            temp -> next = newFile;
            temp = temp -> next;
        }
        newFile -> next = NULL;
    }
    Display();
}