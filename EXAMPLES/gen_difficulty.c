#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bl3mod.h"

/*
 * libbl3mod/B3MT CSL example: difficulty through damage...
 */

FILE* outFile;

int main() {
    char* modheader;
    char* currentLine;
    char* currentSet;
    int i;
    printf("(B3MT module/libbl3mod test program) Difficulty curve editor. \n");
    outFile = fopen("difficulty.bl3hotfix", "w");
    if(!outFile) {
        printf("Failed to open output file!\n");
        exit(1);
    }
    modheader = header("Difficulty", "HS", "asdf", "1.0.0");
    fwrite(modheader, sizeof(char), strlen(modheader), outFile);
    printf("Done.\n");
    return 0;
}
