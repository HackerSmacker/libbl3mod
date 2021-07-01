#include <stdio.h>
#include "bl3mod.h"

// SparkLevelPatchEntry,(1,6,0,Sanctuary3_P),/Game/Maps/Sanctuary3,/Game/InteractiveObjects/MissionSpecificObjects/DynastyDiner/Burger/Model/Meshes,SM_DynastyDiner_Burger,90,"14700.000000,8269.000000,-685.000000|0.000000,0.000000,0.000000|3.000000,3.000000,3.000000",0
// SparkLevelPatchEntry,(1,6,0,Sanctuary3_P),/Game/Maps/Sanctuary3,/Game/InteractiveObjects/MissionSpecificObjects/DynastyDiner/Burger/Model/Meshes,SM_DynastyDiner_Burger,90,"14700.000000,8269.000000,-685.000000|0.000000,0.000000,0.000000|3.000000,3.000000,3.000000",0

// SparkPatchEntry,(1,1,0,),/Game/GameData/Balance/HealthAndDamage/Att_UniversalBalanceScaler.Att_UniversalBalanceScaler:BP_ConstantValueResolver_C_0,Value,0,,(BaseValueConstant=1.080)
// SparkPatchEntry,(1,1,0,),/Game/GameData/Balance/HealthAndDamage/Att_UniversalBalanceScaler.Att_UniversalBalanceScaler:BP_ConstantValueResolver_C_0,Value,0,,(BaseValueConstant=1.080)

// SparkEarlyLevelPatchEntry,(1,2,0,MatchAll),/Game/GameData/Balance/HealthAndDamage/HealthBalanceScalers/DataTable_DamageAndHealthScalers.DataTable_DamageAndHealthScalers,AI_AdditionalDamagePerLevel,Scaler_4_FE2B037B42E1F6E76E3AEBAFDCC8DB86,0,,-0.006
// SparkPatchEntry          ,(1,2,0,        ),/Game/GameData/Balance/HealthAndDamage/HealthBalanceScalers/DataTable_DamageAndHealthScalers.DataTable_DamageAndHealthScalers,AI_AdditionalDamagePerLevel,Scaler_4_FE2B037B42E1F6E76E3AEBAFDCC8DB86,0,,-0.006
// SparkEarlyLevelPatchEntry,(1,2,0,MatchAll),/Game/GameData/Balance/HealthAndDamage/HealthBalanceScalers/DataTable_DamageAndHealthScalers.DataTable_DamageAndHealthScalers,AI_AdditionalDamagePerLevel,Scaler_4_FE2B037B42E1F6E76E3AEBAFDCC8DB86,0,,-0.006


// SparkPatchEntry,(1,1,0,),/Game/Gear/Shields/_Design/_Uniques/Transformer/Parts/Shield_Part_Aug_HYP_LGD_Transformer.Shield_Part_Aug_HYP_LGD_Transformer,InventoryAttributeEffects,0,,((AttributeToModify=GbxAttributeData'"/Game/Gear/Shields/_Design/Naming/Att_Shield_IgnoreManufacturerName.Att_Shield_IgnoreManufacturerName"',ModifierType=OverrideBaseValue,ModifierValue=(BaseValueConstant=1)),(AttributeToModify=GbxAttributeData'"/Game/Gear/Shields/_Design/Balance/Attributes/Att_ShieldBalance_ElementalResistance.Att_ShieldBalance_ElementalResistance"',ModifierType=OverrideBaseValue,ModifierValue=(BaseValueConstant=1.25)),(AttributeToModify=GbxAttributeData'"/Game/Gear/Shields/_Design/Balance/Attributes/Att_ShieldBalance_Capacity.Att_ShieldBalance_Capacity"',ModifierType=ScaleSimple,ModifierValue=(BaseValueConstant=10000)))

// /Game/PlayerCharacters/_Shared/_Design/GuardianRank/Attributes/Table_GuardianRank_Balance2

int main() {
	char* ducModTest = regular_hotfix("SparkPatchEntry", "/Game/Gear/Weapons/Pistols/Jakobs/_Shared/_Design/_Unique/TheDuc/Name_JAK_PS_TheDuc.Name_JAK_PS_TheDuc", "PartName", "asdfasdfasdf", 0);
	printf("%s\n", ducModTest);
	char* objExTest = extract_object("/Path/To/Something");
	printf("%s\n", objExTest);
	char* sameThing = set_unique_name("/Game/Gear/Weapons/Pistols/Jakobs/_Shared/_Design/_Unique/TheDuc/Name_JAK_PS_TheDuc", "The Ducccccccc");
	printf("%s\n", sameThing);
	char* burgerOnMap = mesh_hotfix("SparkLevelPatchEntry", "Sanctuary3_P", "/Game/Maps/Sanctuary3", "/Game/InteractiveObjects/MissionSpecificObjects/DynastyDiner/Burger/Model/Meshes", "SM_DynastyDiner_Burger", mesh_coord("14700.000000", "8269.000000", "-685.000000", "0.000000", "0.000000", "0.000000", "3.000000", "3.000000", "3.000000"), 0, 0);
	printf("%s\n", burgerOnMap);
	char* redChange = set_unique_flavortext("/Game/Gear/Weapons/Pistols/Jakobs/_Shared/_Design/_Unique/TheDuc/UIStat_RedText_TheDuc", "WHAT DO I DO");
	printf("%s\n", redChange);
	char* scale = regular_hotfix_multi("SparkPatchEntry", "/Game/GameData/Balance/HealthAndDamage/Att_UniversalBalanceScaler.Att_UniversalBalanceScaler", "BP_ConstantValueResolver_C_0", "Value", "(BaseValueConstant=1.080)", 0);
	printf("%s\n", scale);
	char* scale2 = regular_hotfix_field_multi("SparkPatchEntry", "/Game/GameData/Balance/HealthAndDamage/Att_UniversalBalanceScaler.Att_UniversalBalanceScaler", "BP_ConstantValueResolver_C_0", "Value", "BaseValueConstant", "1.080", 0);
	printf("%s\n", scale2);
	char* tableDamage = table_hotfix_matchall("SparkEarlyLevelPatchEntry", extract_object("/Game/GameData/Balance/HealthAndDamage/HealthBalanceScalers/DataTable_DamageAndHealthScalers"), "AI_AdditionalDamagePerLevel", "Scaler_4_FE2B037B42E1F6E76E3AEBAFDCC8DB86", "-0.006", 0);
	printf("%s\n", tableDamage);
	char* guardianNoMoreCap = table_hotfix("SparkPatchEntry", extract_object("/Game/PlayerCharacters/_Shared/_Design/GuardianRank/Attributes/Table_GuardianRank_Balance2"), "GROWTH_RATE", "Value", "(BaseValueConstant=1.0)", 0);
	printf("%s\n", guardianNoMoreCap);
	return 0;
}
