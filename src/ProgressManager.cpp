#include "ProgressManager.h"
#include <stdio.h>
#include <stdlib.h>

// Get the progress of the hashing operation
uint64_t getProgress() {
    // Get the current progress of the hashing operation, located in the first line of the file
    FILE * tempfs = fopen("progress.txt", "r");
    if(tempfs == NULL) {
        printf("Error: Could not open file\n");
        return 0;
    }
    uint64_t progress;
    fscanf(tempfs, "%llu", &progress);
    fclose(tempfs);
    return progress;
}

// Save the progress of the hashing operation
void saveProgress(uint64_t progress) {
    // Save the current progress of the hashing operation, located in the first line of the file
    FILE * tempfs = fopen("progress.txt", "w");
    fprintf(tempfs, "%llu", progress);
    fclose(tempfs);
}
