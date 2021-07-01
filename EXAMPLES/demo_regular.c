#include <stdio.h>
#include "bl3mod.h"

int main() {
       printf("libbl3mod demo 2 - regular hotfix\n");
       char* result = hotfix(
		       MOD_TYPE_PATCH,
		       "/Game/Cinematics/_Design/NPCs/BPCine_Actor_Typhon.BPCine_Actor_Typhon_C:SkeletalMesh_GEN_VARIABLE",
		       "bEnableUpdateRateOptimizations",
		       "False",
		       0
		       );
       printf(result);
       return 0;
}

