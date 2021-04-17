#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bl3tms.h"

/* LIBBL3MOD SYSTEM CODE: LICENSED UNDER THE TERMS OF THE GPLV3 LICENSE. */
/* FAILURE TO COMPLY WITH THE LICENSE TERMS */
/* SPECIFIED WILL RESULT IN CONSEQUENCES. */

/* Borderlands 3 "OakTMS-prod.cfg" extractor program */
/* Probably the most compatible examplein the libbl3mod set */
/* This should literally compile on ANYTHING. (ANSI C)*/
/* NOTE FOR USERS OF BIG-ENDIAN MACHINES: */
/* Such as: PowerPC, SPARC, System Z/390, etc */
/* You MUST set the #define below! */

#define BIG_ENDIAN

FILE* inFile;
FILE* outFile;

struct tms_file tmsFile;
struct chunk_info* chunkInfo;
struct chunk_data* chunkData;

unsigned int flip_32(unsigned int num) {
    unsigned int swapped;
    swapped = ((num >> 24) & 0xff) |
        ((num << 8) & 0xff0000) |
        ((num >> 8) & 0xff00) |
        ((num << 24) & 0xff000000);
    return swapped;
}

unsigned long flip_64(unsigned long num) {
    unsigned long swapped = num;
    swapped = (swapped & 0x00000000FFFFFFFF) << 32 
	    | (swapped & 0xFFFFFFFF00000000) >> 32;
    swapped = (swapped & 0x0000FFFF0000FFFF) << 16
	    | (swapped & 0xFFFF0000FFFF0000) >> 16;
    swapped = (swapped & 0x00FF00FF00FF00FF) << 8
            | (swapped & 0xFF00FF00FF00FF00) >> 8;
    return swapped;
}

int main(int argc, char** argv) {
    char outFileName[64];
    char ofnNumber[5];
    unsigned long current_comp_size = 0;
    unsigned long current_decomp_size = 0;
    int filePos = 0;
    unsigned int temp;
    int i;
    int size_32;
    int size_64;
    size_32 = sizeof(unsigned int);
    size_64 = sizeof(unsigned long);

    if(argc < 2) {
        printf("File not specified.\n");
        exit(1);
    }
    inFile = fopen(argv[1], "r");
    if(!inFile) {
        printf("Failed to open input file.\n");
        exit(1);
    }
    /* 0. Read header */
    printf("Reading file...\n");
    fread(&tmsFile.decomp_size, size_32, 1, inFile);
    fread(&tmsFile.num_files, size_32, 1, inFile);
    fread(&tmsFile.magic, size_64, 1, inFile);
    fread(&tmsFile.max_decomp_size, size_64, 1, inFile);
    fread(&tmsFile.total_comp_size, size_64, 1, inFile);
    fread(&tmsFile.decomp_size_2, size_64, 1, inFile);
#ifdef BIG_ENDIAN
    tmsFile.decomp_size = swap_32(tmsFile.decomp_size);
    tmsFile.num_files = swap_32(tmsFile.num_files);
    tmsFile.magic = swap_64(tmsFile.magic);
    tmsFile.max_decomp_size = swap_64(tmsFile.max_decomp_size);
    tmsFile.total_comp_size = swap_64(tmsFile.total_comp_size);
    tmsFile.decomp_size_2 = swap_64(tmsFile.decomp_size_2);
#endif
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
        printf("WARNING WARNING the two decompressed size fields");
        printf("are NOT equal! (endianess check!)\n");
    }
    /* 1. Read chunk info block */
    for(;;) {
        fread(&chunkInfo[filePos].comp_size, 
            size_64, 1, inFile);
        fread(&chunkInfo[filePos].decomp_size, 
            size_64, 1, inFile);
        current_comp_size += chunkInfo[filePos].comp_size;
        current_decomp_size += chunkInfo[filePos].decomp_size;
        filePos++;
        printf("Total compressed size so far: %d\n", current_comp_size);
        if(current_comp_size == tmsFile.total_comp_size) {
            printf("Done reading chunk info.\n");
            break;
        }
    }
    
    /* 2. Display chunk size information */
    for(i = 0; i < filePos; i++) {
        printf("Chunk %d compressed size: %lu\n", i, 
            chunkInfo[i].comp_size);
        printf("Chunk %d decompressed size: %lu\n", i, 
            chunkInfo[i].decomp_size);
    }
    /* 3. Read in the data */
    for(i = 0; i < filePos; i++) {
        printf("Reading %d bytes... ", chunkInfo[i].comp_size);
        fread(&chunkData[i].data, sizeof(char), 
            chunkInfo[i].comp_size, inFile);
        printf("done\n");
    }
    /* 4. Skip decompression. */
    /* 5. Write files to disk */
    for(i = 0; i < filePos; i++) {
        memset(outFileName, 0x00, 64);
        memset(ofnNumber, 0x00, 5);
        strcpy(outFileName, "tmsOut-");
        sprintf(ofnNumber, "%d", i);
        strcat(outFileName, ofnNumber);
        printf("Writing file %d: %s...", i, outFileName);
        outFile = fopen(outFileName, "w");
        fwrite(&chunkData[i].data, sizeof(char),
             chunkInfo[i].comp_size, outFile);
        fclose(outFile);
        printf("done\n");
    }
    printf("Done. Thank you for choosing libbl3mod.\n");
    fclose(inFile);
    return 0;
}
