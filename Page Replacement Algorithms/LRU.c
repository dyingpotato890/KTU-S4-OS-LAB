#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lastused[3];
int MAX_FRAMES;
int hitCount = 0, missCount = 0;

void initialize(int frames[]) {
    for (int i = 0; i < MAX_FRAMES; i++)
        frames[i] = -1;

    memset(lastused, 0, sizeof(lastused));
}

void displayFrames(int frames[]) {
    for (int i = 0; i < MAX_FRAMES; i++) {
        if (frames[i] != -1)
            printf("%d ", frames[i]);
        else
            printf("- ");
    }
    printf("\n");
}

void LRU(int frames[], int pages[], int n) {
    int page_faults = 0;
    int next = -1;

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        // Check if page already exists in frames
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == page) {
                printf("Page %d already in frame %d\n", page, j);
                found = 1;
                hitCount++;
                break;
            }
        }

        if (!found) {
            missCount++;
            next = (next + 1) % MAX_FRAMES;  // Circularly select the next frame
            printf("Page %d loaded in frame %d\n", page, next);
            frames[next] = page;
            page_faults++;
        }

        displayFrames(frames);
    }

    printf("\nTotal Page Faults: %d\n", page_faults);
    printf("Hit Count: %d\n", hitCount);
    printf("Miss Count: %d\n", missCount);
    printf("\nHit Ratio = %f", (float)hitCount / (float)(hitCount + missCount));
    printf("\nMiss Ratio = %f", (float)missCount / (float)(hitCount + missCount));
}

int main() {
    int n;
    int pages[20];

    printf("Enter the number of page requests: ");
    scanf("%d", &n);

    printf("Enter the page reference sequence: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter The Number of Frames: ");
    scanf("%d", &MAX_FRAMES);

    int frames[MAX_FRAMES];

    initialize(frames);
    LRU(frames, pages, n);

    return 0;
}
