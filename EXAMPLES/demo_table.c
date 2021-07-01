#include <stdio.h>
#include "bl3mod.h"

int main() {
       printf("libbl3mod demo 1 - table hotfix\n");
       char* result = table_hotfix(MOD_TYPE_PATCH,
               "/Game/GameData/Modifiers/DataTable_Mayhem_CoreMods_Easy",
               "ExpGain_CombatOnly",
               "MinValue",
               "100.000000",
               0);
       printf(result);
       return 0;
}

