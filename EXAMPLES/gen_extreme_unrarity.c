#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bl3mod.h"

/*
 * Another libbl3mod example.
 * Changes the chances you are going to get items, i.e. the scaling values.
 * Usage: gen_extreme_unrarity (no arguments required)
 * Output: extreme_unrarity.bl3hotfix (line-delimited format)
 * Bug report: N/A
 */

FILE* outFile;
char* object = "/Game/GameData/Loot/RarityWeighting/DataTable_ItemRarity";
char* object2 = "/Game/GameData/Loot/RarityWeighting/DataTable_Lootable_BalanceData";
char* levels[] = {
    "Common",
    "Uncommon",
    "Rare",
    "VeryRare",
    "Legendary"
};
char* base = "BaseWeight_7_F9F7E65D4BC13F8CB481169592B2D191";
char* exponent = "ExponentForGrowthRate_11_A513926441E7F0780725D5AA7B68A29A";
char* itemsources[] = {
    "Normal",
    "VeryGood",
    "WhiteChest",
    "RedChest",
    "GoldenChest",
    "Badass",
    "Anointed",
    "SuperBadass",
    "UltimateBadass",
    "VendingMachine",
    "TrialsChestNoGem",
    "TrialsChestTwoGems",
    "TrialsChestThreeGems",
    "TrialsChestFourGems",
    "TyphonDeadDrop",
    "VeteranVendingMachine",
    "LilithEndChest"
};
char* isfields[] = {
    "RarityWeightLevelBias_5_057BA6074423BC84C3853592FAE98B1F",
    "CommonWeightModifier_21_3D483428462299E5B6AF02B6CC0F65CC",
    "UncommonWeightModifier_12_A1CB19B648A9D93482D9DC83713A2FB5",
    "RareWeightModifier_16_F11E138D458B57D473F062A6C52A5F58",
    "VeryRareWeightModifier_17_8A0A186D4D4FC53ADDFB71A8A7F589DA",
    "LegendaryWeightModifier_18_B98DE11946C28DF64D94E197F7FED9BE"
};
char* isfieldshumanreadable[] = {
    "RarityWeightLevelBias",
    "CommonWeightModifier",
    "UncommonWeightModifier",
    "RareWeightModifier",
    "VeryRareWeightModifier",
    "LegendaryWeightModifier"
};

int main() {
    char* modheader;
    char* currentLine;
    char toValueNumber[8];
    int i;
    int j;
    printf("(B3MT module/libbl3mod test program) Change scaling: drop chance exponent value.\n");
    outFile = fopen("extreme_unrarity.bl3hotfix", "w");
    if(!outFile) {
        printf("Failed to open output file!\n");
        exit(1);
    }
    modheader = header("Extreme (Un)Rarity", "HS", "Changes drop scale.", "1.0.0");
    fwrite(modheader, sizeof(char), strlen(modheader), outFile);
    printf("Please specify the new values in decimal form (for instance, 50%% is 0.50 and 100%% is 1.00).\n");
    printf("These prompts will ask you to change the overall scaling values.\n");
    printf("To skip changing a value, just strike enter.\n");
    for(i = 0; i < 5; i++) {
        printf("Enter base scale for rarity level %s: ", levels[i]);
        gets(toValueNumber);
        if(strcmp(toValueNumber, "") == 0) {
            printf("Skipping.\n");
            continue;
        }
        else {
            currentLine = table_hotfix(MOD_TYPE_PATCH, extract_object(object), levels[i], base, toValueNumber, 0);
            fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);
        }
        printf("Enter exponent scale for rarity level %s: ", levels[i]);
        gets(toValueNumber);
        if(strcmp(toValueNumber, "") == 0) {
            printf("Skipping.\n");
            continue;
        }
        else {
            currentLine = table_hotfix(MOD_TYPE_PATCH, extract_object(object), levels[i], exponent, toValueNumber, 0);
            fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);
        }
    }
    printf("These prompts will allow you to set loot chances for specific loot sources.\n");
    for(i = 0; i < 17; i++) {
        printf("Changing loot chances for source %s\n", itemsources[i]);
        for(j = 0; j < 6; j++) {
            printf("Please specify the value for %s: ", isfieldshumanreadable[j]);
            gets(toValueNumber);
            if(strcmp(toValueNumber, "") == 0) {
                printf("Skipping.\n");
                continue;
            }
            else {
                currentLine = table_hotfix(MOD_TYPE_PATCH, extract_object(object2), itemsources[i], isfields[j], toValueNumber, 0);
                fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);
            }
        }
    }
    printf("Done.\n");
    return 0;
}
