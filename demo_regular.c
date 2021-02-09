#include <stdio.h>
#include "bl3mod.h"
#include "bl3modtype.h"

int main() {
       printf("libbl3mod demo 2 - regular hotfix\n");
       char* result = regular_hotfix(
		       mod_type_patch,
		       "Crypt_P",
		       "/Game/Cinematics/_Design/NPCs/BPCine_Actor_Typhon.BPCine_Actor_Typhon_C:SkeletalMesh_GEN_VARIABLE",
		       "bEnableUpdateRateOptimizations",
		       "True",
		       "False",
		       0
		       );
       printf(result);
       return 0;
}

