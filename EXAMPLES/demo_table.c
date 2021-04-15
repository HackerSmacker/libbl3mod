#include <stdio.h>
#include "bl3mod.h"
#include "bl3modtype.h"

int main() {
       printf("libbl3mod demo 1 - table hotfix\n");
       char* result = table_hotfix(mod_type_patch,
               "/Game/GameData/Modifiers/DataTable_Mayhem_CoreMods_Easy",
               "ExpGain_CombatOnly",
               "MinValue",
               "2.000000",
               "0.100000",
               0);
       printf(result);
       return 0;
}

