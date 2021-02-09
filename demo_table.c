#include <stdio.h>
#include "bl3mod.h"
#include "bl3modtype.h"

int main() {
       printf("libbl3mod demo 1 - table hotfix\n");
       char* result = table_hotfix(mod_type_patch,
               "/Game/Gear/Weapons/_Shared/_Design/GameplayAttributes/_Unique/DataTable_WeaponBalance_Unique_MAL",
               "SR_Krakatoa",
               "DamageScale_2_4F6EF14648BA8F2AE9217DAFEA60EE53",
               "0",
               "2.5",
               "",
               0);
       printf(result);
       return 0;
}

