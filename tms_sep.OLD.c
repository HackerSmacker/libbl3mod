#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "bl3tms.h"

FILE* inFile;
FILE* outFile;

struct tms_file tmsFile;
struct chunk_info* chunkInfo;
struct chunk_data* chunkData;

uint32_t flip(uint32_t num) {
    uint32_t swapped;
    swapped = ((num >> 24) & 0xff) |
        ((num << 8) & 0xff0000) |
        ((num >> 8) & 0xff00) |
        ((num << 24) & 0xff000000);
    return swapped;
}

int main(int argc, char** argv) {
    char outFileName[64];
    char ofnNumber[5];
    uint64_t current_comp_size = 0;
    uint64_t current_decomp_size = 0;
    int filePos = 0;
    uint32_t temp;
    int i;

    if(argc < 2) {
		printf("Incorrect number of arguments (specify an input file)\n");
		exit(1);
	}
    inFile = fopen(argv[1], "r");
    if(!inFile) {
        printf("Failed to open input file.\n");
        exit(1);
    }
    // 0. Read header
    printf("Reading file...\n");
    fread(&tmsFile.decomp_size, sizeof(uint32_t), 1, inFile);
    fread(&tmsFile.num_files, sizeof(uint32_t), 1, inFile);
    fread(&tmsFile.magic, sizeof(uint64_t), 1, inFile);
    fread(&tmsFile.max_decomp_size, sizeof(uint64_t), 1, inFile);
    fread(&tmsFile.total_comp_size, sizeof(uint64_t), 1, inFile);
    fread(&tmsFile.decomp_size_2, sizeof(uint64_t), 1, inFile);
    printf("File information:\n");
    printf("Total decompressed size: %lu\n", tmsFile.decomp_size);
    printf("Number of files in archive: %lu\n", tmsFile.num_files);
    printf("Magic number: %lu\n", tmsFile.magic);
    printf("Maximum decompressed size: %lu\n", tmsFile.max_decomp_size);
    printf("Total compressed size: %lu\n", tmsFile.total_comp_size);
    printf("Total decompressed size 2: %lu\n", tmsFile.decomp_size_2);
    chunkInfo = malloc(99 * sizeof(struct chunk_info));
    chunkData = malloc(99 * sizeof(struct chunk_data));
    if(tmsFile.decomp_size != tmsFile.decomp_size_2) {
        printf("WARNING WARNING WARNING the two decompressed size fields are NOT equal! Expect a SIGSEGV on the next line or so!\n");
    }
    // 1. Read chunk info block
    for(;;) {
        fread(&chunkInfo[filePos].comp_size, sizeof(uint64_t), 1, inFile);
        fread(&chunkInfo[filePos].decomp_size, sizeof(uint64_t), 1, inFile);
        current_comp_size += chunkInfo[filePos].comp_size;
        current_decomp_size += chunkInfo[filePos].decomp_size;
        filePos++;
        printf("Total compressed size so far: %d\n", current_comp_size);
        if(current_comp_size == tmsFile.total_comp_size) {
            printf("Done reading chunk info.\n");
            break;
        }
    }
    
    // 2. Display chunk size information
    for(i = 0; i < filePos; i++) {
        printf("Chunk %d compressed size: %lu\n", i, chunkInfo[i].comp_size);
        printf("Chunk %d decompressed size: %lu\n", i, chunkInfo[i].decomp_size);
    }
    // 3. Read in the data
    for(i = 0; i < filePos; i++) {
        printf("Reading %d bytes... ", chunkInfo[i].comp_size);
        fread(&chunkData[i].data, sizeof(char), chunkInfo[i].comp_size, inFile);
        printf("done\n");
    }
    // 4. Skip decompression.
    // 5. Write files to disk
    for(i = 0; i < filePos; i++) {
        memset(outFileName, 0x00, 64);
        memset(ofnNumber, 0x00, 5);
        strcpy(outFileName, "tmsOut-");
        sprintf(ofnNumber, "%d", i);
        strcat(outFileName, ofnNumber);
        printf("Writing file %d: %s...", i, outFileName);
        outFile = fopen(outFileName, "w");
        fwrite(&chunkData[i].data, sizeof(char), chunkInfo[i].comp_size, outFile);
        fclose(outFile);
        printf("done\n");
    }
    printf("Done. Thank you for choosing libbl3mod.\n");
    fclose(inFile);
    return 0;
}
