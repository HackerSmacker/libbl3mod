#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bl3mod.h"

/*
 * libbl3mod/B3MT CSL example
 * This mod adds a Pearlescent rarity.
 * VERY IMPORTANT NOTE: I DID NOT FIGURE ANY OF THIS OUT. EPICNNG DID.
 * I JUST WROTE THIS PROGRAM TO GENERATE IT AS A POC.
 */

/* NOTE - DOES NOT COMPILE ON VMS */

char* rarityDataObject = "/Game/GameData/Loot/RarityData/RarityData_01_Common.RarityData_01_Common";
char* yellowRarityDataObject = "/Game/GameData/Loot/RarityData/RarityData_05_Legendary.RarityData_05_Legendary";
char* statsDataObject = "/Game/Gear/Weapons/_Shared/_Design/GameplayAttributes/Weapon_Initialization/DataTable_Weapon_Rarity_Stats";
char* levelUpSoundEffect = "/Game/Audio/Events/UX/HUD/Character_Global/WE_HUD_Global_Level_Up.WE_HUD_Global_Level_Up";
char* mapIcon = "/Game/GameData/ZoneMap/POI_Types/POI_LegendaryPickup.POI_LegendaryPickup";
char* economyPriceScaler = "GbxAttributeData\'\"/Game/GameData/Economy/Rarity/Att_RarityCostMultiplier_05_Legendary.Att_RarityCostMultiplier_05_Legendary\"\'";

FILE* outFile;

int main() {
    char* header;
    char* currentLine;
    int i;
    printf("(B3MT module/libbl3mod test program) Remap Common to be Pearlescent. \n");
    outFile = fopen("pearls.bl3hotfix", "w");
    if(!outFile) {
        printf("Failed to open output file!\n");
        exit(1);
    }
    header = mod_header("Pearlescents", "HS", "GAMER", "1.0.0");
    fwrite(header, sizeof(char), strlen(header), outFile);
    
    // Change rarity color and outline color.
    currentLine = regular_hotfix(MOD_TYPE_PATCH, rarityDataObject, "RarityColorFX", "(r=0.020,g=0.978,b=0.882,a=1)", 0);
    fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);
    currentLine = regular_hotfix(MOD_TYPE_PATCH, rarityDataObject, "RarityColorOutline", "(r=0.020,g=0.978,b=0.882,a=1)", 0);
    fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);

    // Rarity frame name?
    currentLine = regular_hotfix(MOD_TYPE_PATCH, rarityDataObject, "RarityFrameName", "Mission", 0);
    fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);

    // Display name
    currentLine = regular_hotfix(MOD_TYPE_PATCH, rarityDataObject, "RarityDisplayname", "PEARLESCENT", 0);
    fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);

    // Drop sound effect
    currentLine = regular_hotfix(MOD_TYPE_PATCH, rarityDataObject, "RarityLootAudioStinger", levelUpSoundEffect, 0);
    fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);

    // Drop icon
    currentLine = regular_hotfix(MOD_TYPE_PATCH, rarityDataObject, "ZoneMapPOIType", mapIcon, 0);
    fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);
    
    // Retain the drop icon for oranges
    currentLine = regular_hotfix(MOD_TYPE_PATCH, yellowRarityDataObject, "ZoneMapPOIType", mapIcon, 0);
    fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);

    // Score modifier
    currentLine = regular_hotfix(MOD_TYPE_PATCH, rarityDataObject, "ItemScoreRarityModifier.BaseValueConstant", "1.3", 0);
    fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);

    // Price modifier
    currentLine = regular_hotfix(MOD_TYPE_PATCH, rarityDataObject, "MonetaryValueModifier.BaseValueAttribute", economyPriceScaler, 0);
    fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);

    // Stats
    currentLine = table_hotfix(MOD_TYPE_PATCH, rarityDataObject, "Common", "DamageScale_6_44C1C8784B7991DCCCF68DA3127A53C0", "1.3", 0);
    fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);
    currentLine = table_hotfix(MOD_TYPE_PATCH, rarityDataObject, "Common", "SpreadScale_8_D7376BDD4BB47794C6ECD995F0B66F07", "0.9", 0);
    fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);
    currentLine = table_hotfix(MOD_TYPE_PATCH, rarityDataObject, "Common", "FireRateScale_11_10E7E12E4756B0EAD899BE8513F300AC", "1.1", 0);
    fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);
    currentLine = table_hotfix(MOD_TYPE_PATCH, rarityDataObject, "Common", "ElementalChanceScale_14_7044338B492EDD3EB1E5E2A58FA9113B", "1.3", 0);
    fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);


    printf("Done.\n");
    return 0;
}
