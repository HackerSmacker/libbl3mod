#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bl3mod.h"

FILE* outFile;

char* values[] = {
    "GROWTH_RATE",
    "GunDamage",
    "CriticalDamage",
    "GrenadeDamage",
    "MeleeDamage",
    "VehicleDamage",
    "GunFireRate",
    "MaxHealth",
    "ShieldCapacity",
    "ShieldRegenRate",
    "ShieldRegenDelay",
    "InjuredDuration",
    "InjuredMoveSpeed",
    "Accuracy",
    "ReloadSpeed",
    "RecoilReduction",
    "LuckyRarityRate",
    "Cooldown"
};

char* dataTable = "/Game/PlayerCharacters/_Shared/_Design/GuardianRank/Attributes/Table_GuardianRank_Balance2";
char* attr = "Value";

int main() {
    char* modheader;
    char* currentLine;
    char toValue[64];
    char toValueNumber[8];
    int i;
    printf("(B3MT/libbl3mod test program) Remove Guardian Rank scaling caps.\n");
    printf("Please specify the new cap in decimal form (for instance, 50%% is 0.50 and 100%% is 1.00): ");
    gets(toValueNumber);
    strcpy(toValue, "(BaseValueConstant=");
    strcat(toValue, toValueNumber);
    strcat(toValue, ")");
    outFile = fopen("no_guardian_cap.bl3hotfix", "w");
    if(!outFile) {
        printf("Failed to open output file!\n");
        exit(1);
    }
    printf("Writing no_guardian_cap.bl3hotfix... ");
    modheader = header("No More 15% Guardian Cap", "HS", "Remove Guardian Rank cap.", "1.0.0");
    fwrite(modheader, sizeof(char), strlen(modheader), outFile);
    for(i = 0; i < 17; i++) {
        currentLine = table_hotfix(MOD_TYPE_PATCH, extract_object(dataTable), values[i], attr, toValue, 0);
        fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);
    }
    printf("Done.\n");
    return 0;
}
