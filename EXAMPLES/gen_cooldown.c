#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bl3mod.h"

/* BL3MOD EXAMPLE CODE */
/* Warning - this is NOT tested at all (literally, at all) */

FILE* outFile;

char* basePath = "/Game/PlayerCharacters/_Shared/_Design/Pools/";
char* objs[] = {
    "ResourcePool_Siren_Phasetrance_CooldownTime",
    "ResourcePool_Beastmaster_Cooldown_Skill1",
    "ResourcePool_Beastmaster_Cooldown_Skill2",
    "ResourcePool_Beastmaster_Cooldown_Skill3",
    "ResourcePool_Gunner_Cooldown",
    "ResourcePool_Operative_DeployBarrier_CooldownTime",
    "ResourcePool_Operative_DigiClone_CooldownTime",
    "ResourcePool_Operative_GRMLN_CooldownTime"
};
char* attr = "BaseActiveRegenerationRate";

int main() {
    char* currentLine;
    char* selectedPath;
    char* toValueNumber;
    int i;
    printf("(B3MT/libbl3mod test program) Change action skill cooldown quickness.\n");
    printf("Enter the values as a full decimal, like 1.2 or 2.0 or 3.4\n");
    outFile = fopen("cooldown.bl3hotfix", "w");
    if(!outFile) {
        printf("Failed to open output file!\n");
        exit(1);
    }
    printf("Writing cooldown.bl3hotfix... ");
    for(i = 0; i < 8; i++) {
	selectedPath = malloc(4096);
	memset(selectedPath, 0x00, 4096);
	sprintf(selectedPath, "%s%s.%s", basePath, objs[i], objs[i]);
	printf("Enter value for %s\n", selectedPath);
	/* I love a good (bad) gets() */
	toValueNumber = malloc(8);
	memset(toValueNumber, 0x00, 8);
	gets(toValueNumber);
	currentLine = malloc(8192);
	memset(currentLine, 0x00, 8192);
	currentLine = regular_hotfix(MOD_TYPE_PATCH, selectedPath, attr, toValueNumber, 0);
	fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);
    }
    printf("Done.\n");
    return 0;
}
