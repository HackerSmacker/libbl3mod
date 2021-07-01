#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bl3mod.h"

/* LICENSED INTERNAL CODE - NOT FOR PUBLIC RELEASE */
/* IF YOU HAVE THIS SOURCE CODE (OR COMPILED BINARY) WITHOUT */
/* THE WRITTEN APPROVAL OF HS, DESTROY IT RIGHT NOW. */

/* libbl3mod example - turn on events at your will. */

FILE* outFile;

/* Paths to the base objects/ */
char* gameplayGlobals = "/Game/GameData/GameplayGlobals";
char* spawnControl = "/Game/GameData/Spawning/GlobalSpawnDLCData";
char* missionPoint = "/Game/Maps/Sanctuary3/Sanctuary3_Season.Sanctuary3_Season:PersistentLevel.OakMissionSpawner_1.SpawnerComponent.SpawnerStyle_SpawnerStyle_Single";
char* mainMenu = "/Game/Common/_Design/Table_MicropatchSwitches";

/* to-vals for the spawn data choices */
char* toVal_Cartels = "((Data=/Game/PatchDLC/Event2/GameData/SpawnDLCSCripts/SpawnDLC_Cartels.SpawnDLC_Cartels,IsEnabled=(BaseValueConstant=1.000000)))";
char* toVal_Hearts2020 = "((Data=/Game/PatchDLC/EventVDay/GameData/SpawnDLCScripts/SpawnDLC_VDay.SpawnDLC_VDay,IsEnabled=(BaseValueConstant=1.000000)))";

/* to-vals for the mission spawner */
char* toVal_Mission_Cartels = "SpawnOptionData'/Game/PatchDLC/Event2/NonPlayerCharacters/LeagueNPC/_Design/Spawning/SpawnOptions_LeagueNPC_Season02.SpawnOptions_LeagueNPC_Season02'";
char* toVal_Mission_Hearts2020 = "SpawnOptionData'/Game/PatchDLC/EventVDay/NonPlayerCharacters/LeagueNPC/_Design/Spawning/SpawnOptions_LeagueNPC_VDay.SpawnOptions_LeagueNPC_VDay'";

/* Some Gearbox-provided bug fixes */
/* Yes, I know I'm "cheating" by using pre-made stuff, but it'll be ok */
char* bugfix_cartels[1] = {"SparkLevelPatchEntry,(1,1,0,Cartels_P),/Game/PatchDLC/Event2/Maps/Cartels_Mission.Cartels_Mission:PersistentLevel.OakMissionWaypointBox_ACtivateStairSlide.CollisionComp,RelativeScale3D,0,,(X=1.000000,Y=1.000000,Z=1.600000)"};
char* bugfix_hearts2020[9] = {
    "SparkCharacterLoadedEntry,(1,2,0,BPChar_PunkBasic),/Game/PatchDLC/EventVDay/Enemies/Hearts/_Shared/Balance/Table_VDay_LootRarityBalance.Table_VDay_LootRarityBalance,LootHeart,LegendaryWeightModifier_18_B98DE11946C28DF64D94E197F7FED9BE,0,,6500\n",
    "SparkCharacterLoadedEntry,(1,2,0,BPChar_RakkBasic),/Game/PatchDLC/EventVDay/Enemies/Hearts/_Shared/Balance/Table_VDay_LootRarityBalance.Table_VDay_LootRarityBalance,LootHeart,LegendaryWeightModifier_18_B98DE11946C28DF64D94E197F7FED9BE,0,,6500\n",
    "SparkCharacterLoadedEntry,(1,2,0,BPChar_GuardianWraith),/Game/PatchDLC/EventVDay/Enemies/Hearts/_Shared/Balance/Table_VDay_LootRarityBalance.Table_VDay_LootRarityBalance,LootHeart,LegendaryWeightModifier_18_B98DE11946C28DF64D94E197F7FED9BE,0,,6500\n",
    "SparkCharacterLoadedEntry,(1,2,0,BPChar_ApeBasic),/Game/PatchDLC/EventVDay/Enemies/Hearts/_Shared/Balance/Table_VDay_LootRarityBalance.Table_VDay_LootRarityBalance,LootHeart,LegendaryWeightModifier_18_B98DE11946C28DF64D94E197F7FED9BE,0,,6500\n",
    "SparkCharacterLoadedEntry,(1,2,0,BPChar_LoaderBasic),/Game/PatchDLC/EventVDay/Enemies/Hearts/_Shared/Balance/Table_VDay_LootRarityBalance.Table_VDay_LootRarityBalance,LootHeart,LegendaryWeightModifier_18_B98DE11946C28DF64D94E197F7FED9BE,0,,6500\n",
    "SparkCharacterLoadedEntry,(1,2,0,BPChar_NogBasic),/Game/PatchDLC/EventVDay/Enemies/Hearts/_Shared/Balance/Table_VDay_LootRarityBalance.Table_VDay_LootRarityBalance,LootHeart,LegendaryWeightModifier_18_B98DE11946C28DF64D94E197F7FED9BE,0,,6500\n",
    "SparkCharacterLoadedEntry,(1,2,0,BPChar_Ratch),/Game/PatchDLC/EventVDay/Enemies/Hearts/_Shared/Balance/Table_VDay_LootRarityBalance.Table_VDay_LootRarityBalance,LootHeart,LegendaryWeightModifier_18_B98DE11946C28DF64D94E197F7FED9BE,0,,6500\n",
    "SparkPatchEntry,(1,2,0,),/Game/PatchDLC/EventVDay/Gear/Weapon/DataTable_WeaponBalance_EventVDay.DataTable_WeaponBalance_EventVDay,PolyAim,MinGameStage_5_E12DB0C74420238367FBC1A5221AFB84,0,,65\n",
    "SparkPatchEntry,(1,2,0,),/Game/PatchDLC/EventVDay/Gear/Weapon/DataTable_WeaponBalance_EventVDay.DataTable_WeaponBalance_EventVDay,WeddingInvitation,MinGameStage_5_E12DB0C74420238367FBC1A5221AFB84,0,,65\n"
};
char* bugfix_hearts2021[2] = {
    "SparkPatchEntry,(1,2,0,),/Game/PatchDLC/EventVDay/Gear/Weapon/DataTable_WeaponBalance_EventVDay.DataTable_WeaponBalance_EventVDay,PolyAim,MinGameStage_5_E12DB0C74420238367FBC1A5221AFB84,0,,65\n",
    "SparkPatchEntry,(1,2,0,),/Game/PatchDLC/EventVDay/Gear/Weapon/DataTable_WeaponBalance_EventVDay.DataTable_WeaponBalance_EventVDay,WeddingInvitation,MinGameStage_5_E12DB0C74420238367FBC1A5221AFB84,0,,65\n"
};


int main() {
    char* modheader;
    char* currentLine;
    char playerChoice[8];
    int i;
    int j;
    printf("(B3MT module/libbl3mod test program) Enable or disable events.\n");
    outFile = fopen("events.bl3hotfix", "w");
    if(!outFile) {
        printf("Failed to open output file!\n");
        exit(1);
    }
    modheader = header("Timed events", "HackerSmacker", "Start timed events whenever.", "1.0");
    fwrite(modheader, sizeof(char), strlen(modheader), outFile);
    printf("What event do you want? You can really only have 1 at a time...\n");
    printf("1 - Bloody Harvest 2019\n");
    printf("2 - Bloody Harvest 2020\n");
    printf("3 - Broken Hearts 2020\n");
    printf("4 - Broken Hearts 2021\n");
    printf("5 - Revenge of the Cartels 2020\n");
    gets(playerChoice);
    if(strcmp(playerChoice, "5") == 0) {
        /* Enable the "league" */
        currentLine = hotfix(MOD_TYPE_PATCH, extract_object(gameplayGlobals), "LeagueInstance", "1", 0);
        fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);
        currentLine = hotfix(MOD_TYPE_PATCH, extract_object(gameplayGlobals), "ActiveLeague", "OL_TheCartels", 0);
        fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);
        currentLine = hotfix(MOD_TYPE_PATCH, extract_object(spawnControl), "DLCs", toVal_Cartels, 0);
        fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);
        currentLine = hotfix_level(MOD_TYPE_EARLYLEVEL, "Sanctuary3_P", missionPoint, "SpawnOptions", toVal_Mission_Cartels, 0);
        fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);
        /* Main menu */
        currentLine = table_hotfix(MOD_TYPE_PATCH, extract_object(mainMenu), "MainMenuAltBackground", "Value", "(BaseValueConstant=5)", 0);
        fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);
        /* Bugfixes */
        fwrite(bugfix_cartels[0], sizeof(char), strlen(bugfix_cartels[0]), outFile);
        goto end;
    }
    else if(strcmp(playerChoice, "3") == 0) {
        /* Enable the "league" */
        currentLine = hotfix(MOD_TYPE_PATCH, extract_object(gameplayGlobals), "LeagueInstance", "1", 0);
        fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);
        currentLine = hotfix(MOD_TYPE_PATCH, extract_object(gameplayGlobals), "ActiveLeague", "OL_ValentinesDay", 0);
        fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);
        currentLine = hotfix(MOD_TYPE_PATCH, extract_object(spawnControl), "DLCs", toVal_Hearts2020, 0);
        fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);
        currentLine = hotfix_level(MOD_TYPE_EARLYLEVEL, "Sanctuary3_P", missionPoint, "SpawnOptions", toVal_Mission_Hearts2020, 0);
        fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);
        /* Bugfixes */
        for(i = 0; i < 9; i++) {
            fwrite(bugfix_hearts2020[i], sizeof(char), strlen(bugfix_hearts2020[i]), outFile);
        }
        goto end;
    }
    else if(strcmp(playerChoice, "4") == 0) {
        /* Enable the "league" */
        currentLine = hotfix(MOD_TYPE_PATCH, extract_object(gameplayGlobals), "LeagueInstance", "2", 0);
        fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);
        currentLine = hotfix(MOD_TYPE_PATCH, extract_object(gameplayGlobals), "ActiveLeague", "OL_ValentinesDay", 0);
        fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);
        currentLine = hotfix(MOD_TYPE_PATCH, extract_object(spawnControl), "DLCs", toVal_Hearts2020, 0);
        fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);
        currentLine = hotfix_level(MOD_TYPE_EARLYLEVEL, "Sanctuary3_P", missionPoint, "SpawnOptions", toVal_Mission_Hearts2020, 0);
        fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);
        /* Bugfixes */
        for(i = 0; i < 2; i++) {
            fwrite(bugfix_hearts2021[i], sizeof(char), strlen(bugfix_hearts2021[i]), outFile);
        }
        goto end;
    }
    else {
        printf("Invalid option. Please run the program again!\n");
        goto end;
    }

    
end:
    printf("Done.\n");
    return 0;
}
