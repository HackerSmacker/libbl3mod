#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "bl3mod.h"

/* LIBBL3MOD SYSTEM CODE: LICENSED UNDER THE TERMS OF THE GPLV3 LICENSE. */
/* FAILURE TO COMPLY WITH THE LICENSE TERMS */
/* SPECIFIED WILL RESULT IN CONSEQUENCES. */

char* global_value_scale(char* newScale) {
	/* Yes, I know you can just "return regular_hotfix()"" */
	/* I chose not to for several reasons... */
	char* output;
	output = regular_hotfix_field_multi("SparkPatchEntry", 
		extract_object("/Game/GameData/Balance/HealthAndDamage/Att_UniversalBalanceScaler"),
		"BP_ConstantValueResolver_C_0", "Value", "BaseValueConstant", newScale, 0);
	return output;
}

char* global_enemy_health(char* overall, char* nvhm, char* tvhm) {
	char* line1;
	char* line2;
	char* line3;
	char* output;
	line1 = table_hotfix_matchall("SparkEarlyLevelPatchEntry", 
		extract_object("/Game/GameData/Balance/HealthAndDamage/HealthBalanceScalers/DataTable_DamageAndHealthScalers"), 
		"AI_AdditionalHealthPerLevel", "Scaler_4_FE2B037B42E1F6E76E3AEBAFDCC8DB86", overall, 0);
	line2 = table_hotfix("SparkPatchEntry",
		extract_object("/Game/GameData/Balance/HealthAndDamage/HealthBalanceScalers/DataTable_DamageAndHealthScalers"), 
		"Playthrough1_GlobalHealthScaler", "Scaler_4_FE2B037B42E1F6E76E3AEBAFDCC8DB86", nvhm, 0);
	line3 = table_hotfix("SparkPatchEntry", 
		extract_object("/Game/GameData/Balance/HealthAndDamage/HealthBalanceScalers/DataTable_DamageAndHealthScalers"), 
		"Playthrough2_GlobalHealthScaler", "Scaler_4_FE2B037B42E1F6E76E3AEBAFDCC8DB86", tvhm, 0);
	output = malloc(strlen(line1) + strlen(line2) + strlen(line3) + 4);
	strcpy(output, line1);
	strcat(output, "\n");
	strcat(output, line2);
	strcat(output, "\n");
	strcat(output, line2);
	return output;
}