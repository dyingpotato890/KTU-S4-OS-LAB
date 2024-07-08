#include <stdio.h>
#include <stdlib.h>


struct block{
    int block_no;
    struct block *next;
};

struct file{
    int start_block;
    int length;
    struct block *list;
};

int i, n;

void linkedFile(int blocks[]){
    char c = 'y';
    int count;

    while (c == 'y' || c == 'Y'){
        struct file *ptr = (struct file *)malloc(sizeof(struct file));
        printf("Enter The File Starting Block: ");
        scanf("%d", &(ptr->start_block));

        printf("Enter The File Length: ");
        scanf("%d", &(ptr->length));

        if (blocks[ptr->start_block] == 1)
            printf("Starting Block Already Allocated! Allocation Not Possible.\n");
        else{
            struct block *b = (struct block *)malloc(sizeof(struct block));
            b->block_no = ptr->start_block;
            b->next = NULL;
            ptr->list = b;

            blocks[ptr->start_block] = 1;
            count = 1;
            i = ptr->start_block + 1;

            while (count < ptr->length){
                if (i >= n)
                    i = 0;
                if (blocks[i] == 0){
                    struct block *new_block = (struct block *)malloc(sizeof(struct block));
                    new_block->block_no = i;
                    new_block->next = NULL;
                    struct block *p = ptr->list;
                    while (p != NULL && p->next != NULL)
                        p = p->next;
                    p->next = new_block;
                    count++;
                    blocks[i] = 1;
                }
                i++;
            }
            if (count < ptr->length)
                printf("Allocation Not Possible Due to Insufficient Storage!\n");
            else{
                printf("File Allocated to Disk.\n");
                printf("Linked List of Blocks Allocated to This File: ");
                struct block *p = ptr->list;
                while (p->next != NULL){
                    printf("%d->", p->block_no);
                    p = p->next;
                }
                printf("%d", p->block_no);
            }
        }
        printf("\nAre There More Files? (y/n): ");
        scanf(" %c", &c);
    }
}

int main(void){
    printf("Enter the Number of Free Blocks: ");
    scanf("%d", &n);

    int blocks[n];
    for (int i = 0; i < n; i++)
        blocks[i] = 0;

    linkedFile(blocks);
}