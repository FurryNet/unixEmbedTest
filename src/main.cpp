#include <stdio.h>
#include <stdlib.h>
#include <ProgressManager.h>
#include <openssl/sha.h>
#include <string.h>

FILE * fs;
int main() {
    printf("Loading Hashing Operation...\nEvery 1,000,000th hash will be save to the file system\n");
    fs = fopen("progress.txt", "a+");
    if (fs == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }
    uint64_t progress = getProgress();
    printf("Starting from %llu\n", progress);
    for(;;progress++) {
        // Convert from uint64_t to char *
        char progressStr[21];
        sprintf(progressStr, "%llu", progress);
        // Digest it
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256(reinterpret_cast<unsigned char*>(progressStr), strlen(progressStr), hash);

        // Print the hash as hex
        for(int i=0;i<SHA256_DIGEST_LENGTH;i++)
            printf("%02x", hash[i]);
        printf("\n");
        // Save the hash to the file system every 1,000,000th hash
        if (progress % 1000000 == 0 && progress != 0) {
            fprintf(fs, "%llu: ", progress);
            for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
                fprintf(fs, "%02x", hash[i]);
            fprintf(fs, "\n");
            fflush(fs);
        }
        // Save the progress to the file system every 10,000th hash (prevent frequent writes to the file system)
        if (progress % 10000 == 0 && progress != 0)
            saveProgress(progress);
    }
    return 0;
}