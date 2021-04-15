#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bl3mod.h"

/*
 * libbl3mod/B3MT CSL example: no more Mayhem modifiers.
 */

FILE* outFile;

char* modSets[] = {
    "/Game/PatchDLC/Mayhem2/ModifierSets/ModSet_Mayhem2_EAsy",
    "/Game/PatchDLC/Mayhem2/ModifierSets/ModSet_Mayhem2_Medium",
    "/Game/PatchDLC/Mayhem2/ModifierSets/ModSet_Mayhem2_Hard",
    "/Game/PatchDLC/Mayhem2/ModifierSets/ModSet_Mayhem2_VeryHard"
};

char* modEasy[] = {
    "/Game/PatchDLC/Mayhem2/Abilities/Player/PartyTime/Ability_Mayhem2_PartyTime",
    "/Game/PatchDLC/Mayhem2/Abilities/Player/AimForTheSky/Ability_Mayhem2_AimForTheSky",
    "/Game/PatchDLC/Mayhem2/Abilities/Player/RoidRage/Ability_Mayhem2_RoidRage",
    "/Game/PatchDLC/Mayhem2/Abilities/Player/SoulStealer/Ability_Mayhem2_SoulStealer",
    "/Game/PatchDLC/Mayhem2/Abilities/Shared/Bighetti/Ability_Mayhem2_Bighetti",
    "/Game/PatchDLC/Mayhem2/Abilities/Enemy/FinishThem/Ability_Mayhem2_FinishThem"
};


char* modMedium[] = {
    "/Game/PatchDLC/Mayhem2/Abilities/Player/FloorIsLava/Ability_Mayhem2_FLoorIsLava",
    "/Game/PatchDLC/Mayhem2/Abilities/Enemy/Rally/Ability_Mayhem2_Rally",
    "/Game/PatchDLC/Mayhem2/Abilities/Enemy/FrozenPulse/Ability_Mayhem2_FrozenPulse",
    "/Game/PatchDLC/Mayhem2/Abilities/Enemy/OlSwitcheroo/Ability_Mayhem2_OlSwitcheroo",
    "/Game/PatchDLC/Mayhem2/Abilities/Enemy/ElementalInfusion/Ability_Mayhem2_ElementalInfusion_Corrosive",
    "/Game/PatchDLC/Mayhem2/Abilities/Enemy/ElementalInfusion/Ability_Mayhem2_ElementalInfusion_Cryo",
    "/Game/PatchDLC/Mayhem2/Abilities/Enemy/ElementalInfusion/Ability_Mayhem2_ElementalInfusion_Fire",
    "/Game/PatchDLC/Mayhem2/Abilities/Enemy/ElementalInfusion/Ability_Mayhem2_ElementalInfusion_Radiation",
    "/Game/PatchDLC/Mayhem2/Abilities/Enemy/ElementalInfusion/Ability_Mayhem2_ElementalInfusion_Shock",
    "/Game/PatchDLC/Mayhem2/Abilities/Enemy/HealNo/Ability_Mayhem2_HealNo"
};

char* modHard[] = {
    "/Game/PatchDLC/Mayhem2/Abilities/Enemy/ChainGang/Ability_Mayhem2_ChainGang",
    "/Game/PatchDLC/Mayhem2/Abilities/Enemy/ArcaneEnchanter/Ability_Mayhem2_ArcaneEnchanter",
    "/Game/PatchDLC/Mayhem2/Abilities/Enemy/DroneBuddy/Ability_Mayhem2_DroneBuddy",
    "/Game/PatchDLC/Mayhem2/Abilities/Enemy/EleBreaker/Ability_Mayhem2_Ele_Breaker",
    "/Game/PatchDLC/Mayhem2/Abilities/Player/StayBack/Ability_Mayhem2_StayBack",
    "/Game/PatchDLC/Mayhem2/Abilities/Enemy/BegoneDot/Ability_Mayhem2_BegoneDot"
};

char* modExtreme[] = {
    "/Game/PatchDLC/Mayhem2/Abilities/Enemy/DeathFromBeyond/Ability_Mayhem2_DeathFromBeyond",
    "/Game/PatchDLC/Mayhem2/Abilities/Player/RogueLite/Ability_Mayhem2_RogueLite",
    "/Game/PatchDLC/Mayhem2/Abilities/Player/CriticalFailure/Ability_Mayhem2_CritFail",
    "/Game/PatchDLC/Mayhem2/Abilities/Player/Sharpshot/Ability_Mayhem2_Sharpshot",
    "/Game/PatchDLC/Mayhem2/Abilities/Enemy/PriorityTarget/Ability_Mayhem2_PriorityTarget",
    "/Game/PatchDLC/Mayhem2/Abilities/Enemy/ElementalInfusion/Ability_Mayhem2_ElementalInfusion_All",
};

//SparkPatchEntry,(1,1,0,),/Game/PatchDLC/Mayhem2/ModifierSets/ModSet_Mayhem2_EAsy.ModSet_Mayhem2_EAsy,ModifierSets,0,,((ModifierAbility=/Game/PatchDLC/Mayhem2/Abilities/Player/PartyTime/Ability_Mayhem2_PartyTime.Ability_Mayhem2_PartyTime_C,Weight=(BaseValueConstant=0)))

int main() {
    char* header;
    char* currentLine;
    char* currentSet;
    int i;
    printf("(B3MT module/libbl3mod test program) No Mayhem modifiers to speak of. \n");
    outFile = fopen("no_modifiers.bl3hotfix", "w");
    if(!outFile) {
        printf("Failed to open output file!\n");
        exit(1);
    }
    header = mod_header("No Modifiers", "HS", "asdf", "1.0.0");
    fwrite(header, sizeof(char), strlen(header), outFile);
    currentSet = malloc(512 * sizeof(char));
    for(i = 0; i < 6; i++) {
        #ifdef OLDCOMPILER
        bzero(currentSet, 512);
        #else
        memset(currentSet, 0x00, 512);
        #endif
        sprintf(currentSet, "((ModifierAbility=%s,Weight=(BaseValueConstant=0)))", extract_object_c(modEasy[i]));
        currentLine = regular_hotfix(MOD_TYPE_PATCH, extract_object(modSets[0]), "ModifierSets", currentSet, 0);
        fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);
    }
    for(i = 0; i < 10; i++) {
        #ifdef OLDCOMPILER
        bzero(currentSet, 512);
        #else
        memset(currentSet, 0x00, 512);
        #endif
        sprintf(currentSet, "((ModifierAbility=%s,Weight=(BaseValueConstant=0)))", extract_object_c(modMedium[i]));
        currentLine = regular_hotfix(MOD_TYPE_PATCH, extract_object(modSets[1]), "ModifierSets", currentSet, 0);
        fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);
    }
    for(i = 0; i < 6; i++) {
        #ifdef OLDCOMPILER
        bzero(currentSet, 512);
        #else
        memset(currentSet, 0x00, 512);
        #endif
        sprintf(currentSet, "((ModifierAbility=%s,Weight=(BaseValueConstant=0)))", extract_object_c(modHard[i]));
        currentLine = regular_hotfix(MOD_TYPE_PATCH, extract_object(modSets[2]), "ModifierSets", currentSet, 0);
        fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);
    }
    for(i = 0; i < 6; i++) {
        #ifdef OLDCOMPILER
        bzero(currentSet, 512);
        #else
        memset(currentSet, 0x00, 512);
        #endif
        sprintf(currentSet, "((ModifierAbility=%s,Weight=(BaseValueConstant=0)))", extract_object_c(modExtreme[i]));
        currentLine = regular_hotfix(MOD_TYPE_PATCH, extract_object(modSets[3]), "ModifierSets", currentSet, 0);
        fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);
    }
    printf("Done.\n");
    return 0;
}