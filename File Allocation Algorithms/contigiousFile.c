#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCKS 100

struct File {
    char filename[20];
    int start_block;
    int num_blocks;
};

void allocateContiguous(struct File* file, int startBlock, int numBlocks) {
    strcpy(file->filename, "my_file.txt");
    file->start_block = startBlock;
    file->num_blocks = numBlocks;
}

int main() {
    struct File myFile;

    allocateContiguous(&myFile, 10, 5);

    printf("File Name: %s\n", myFile.filename);
    printf("Start Block: %d\n", myFile.start_block);
    printf("Number of Blocks: %d\n", myFile.num_blocks);

    return 0;
}