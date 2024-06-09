#include <stdio.h>

char memory[25], tempMemory[25];
int topMain = -1, topTemp = -1;

void PushToMemory(char page){
    topMain++;
    memory[topMain] = page;
}

void PushToTemp(char page){
    topTemp++;
    tempMemory[topTemp] = page;
}

char PopFromMemory(){
    char ele = memory[topMain];
    memory[topMain] = ' ';
    topMain--;
    return ele;
}

char PopFromTemp(){
    char ele = tempMemory[topTemp];
    tempMemory[topTemp] = ' ';
    topTemp--;
    return ele;
}

int isInMemory(char page, int n){
    for(int i = 0; i < n; i++){
        if(page == memory[i]){
            return 1;
        }
    }
    return 0;
}

void Execute(char pages[], int n){
    int hitCount = 0, missCount = 0;
    for(int i = 0; i < n; i++){
        memory[i] = ' ';
        tempMemory[i] = ' ';
    }
    for(int i = 0; pages[i] != '\0'; i++){
        while(topMain != -1){
            PushToTemp(PopFromMemory());
        }
        PushToMemory(pages[i]);
        int hitMarker = 0;
        while(topTemp != -1 && topMain != n-1){
            if(isInMemory(tempMemory[topTemp], n) == 0){
                PushToMemory(PopFromTemp());
            }
            else{
                tempMemory[topTemp] = ' ';
                topTemp--;
                hitMarker = 1;
            }
        }

        if(topMain == n-1){
            if(isInMemory(tempMemory[topTemp], n) == 1){
                hitMarker = 1;
            }
            tempMemory[topTemp] = ' ';
            topTemp = -1;
        }

        if(hitMarker == 1) hitCount++;
        else missCount++;

        for(int j = topMain; j >= 0; j--){
            printf("%c ", memory[j], hitMarker);
        }
        printf("\n");
    }

    printf("\nHit Count = %d", hitCount);
    printf("\nMiss Count = %d", missCount);
    printf("\nHit Ratio = %f", (float)hitCount / (float)(hitCount + missCount));
    printf("\nMiss Ratio = %f", (float)missCount / (float)(hitCount + missCount));
}

void main(){
    printf("LRU Page Replacement\n");
    printf("--------------------\n\n");
    printf("Enter the Page String: ");
    char pages[25];
    scanf("%s", pages);
    printf("Enter the number of frames: ");
    int n;
    scanf("%d", &n);

    Execute(pages, n);
}
