#include <stdio.h>
#include "bl3mod.h"

int main() {
       printf("libbl3mod demo 2 - regular hotfix\n");
       char* result = mesh_hotfix(
		       MOD_TYPE_LEVEL,
		       "AtlasHQ_P",
		       "/Game/Maps/Zone_1/AtlasHQ",
		       "/Game/LevelArt/Environments/Promethea/AtlasHQ/Architecture/Pillars/Model/Meshes",
		       "SM_AtlasHQ_Pillar_V1,90",
		       "-9392.000000,-2797.000000,928.000000|0.000000,0.000319,0.000000|1.500000,0.750000,1.500000",
		       0,
		       0
		       );
       printf(result);
       return 0;
}

