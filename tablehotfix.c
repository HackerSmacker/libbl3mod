#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "bl3mod.h"

char* table_hotfix(const char* hf_type, char* package, char* obj_name, 
		char* row_name, char* attr_name, char* new_val,
		char* prev_val, int notificationFlag) {
	char* output;
	char* notFlagChars;
	char* prevValLenChars;
	char* packageEndWithSlash;
	char* packageEnd;
	packageEndWithSlash = strrchr(package, '/');
	packageEnd = malloc(strlen(packageEndWithSlash) - 1);
	strcpy(packageEnd, packageEndWithSlash + 1);
	output = malloc(strlen(hf_type) + strlen(package) + strlen(obj_name)
			+ strlen(row_name) + strlen(attr_name)
			+ strlen(new_val) + 32);
	strcat(output, hf_type);
	strcat(output, ",");
	strcat(output, "(1,2,");
	notFlagChars = malloc(2);
	sprintf(notFlagChars, "%d", notificationFlag);
	strcat(output, notFlagChars);
	strcat(output, ",),");
	strcat(output, package);
	strcat(output, ".");
	strcat(output, packageEnd);
	strcat(output, ",");
	strcat(output, obj_name);
	strcat(output, ",");
	strcat(output, row_name);
	strcat(output, ",");
	strcat(output, attr_name);
	strcat(output, ",");
	prevValLenChars = malloc(16);
	sprintf(prevValLenChars, "%d", strlen(prev_val));
	strcat(output, prevValLenChars);
	strcat(output, ",");
	strcat(output, prev_val);
	strcat(output, ",");
	strcat(output, new_val);
	strcat(output, "\n");
	return output;
}
