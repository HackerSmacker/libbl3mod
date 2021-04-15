#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "bl3mod.h"

// LIBBL3MOD SYSTEM CODE: LICENSED UNDER THE TERMS OF THE GPLV3 LICENSE.

char* set_unique_name(char* object, char* to_val) {
	// memory consumption kludge to make it work with old c compilers
	char* output;
	output = regular_hotfix("SparkPatchEntry", extract_object(object), "PartName", to_val, 0);
	return output;
}

char* set_unique_flavortext(char* object, char* to_val) {
	char* output;
	char* newText;
	newText = malloc(strlen(to_val) + 17);
	strcpy(newText, "[Flavor]");
	strcat(newText, to_val);
	strcat(newText, "[/Flavor]");
	output = regular_hotfix("SparkPatchEntry", extract_object(object), "Text", newText, 0);
	return output;
}