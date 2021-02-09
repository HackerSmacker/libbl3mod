#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "bl3mod.h"

char* table_hotfix(const char* hf_type, char* package,  
		char* row_name, char* attr_name, 
		char* from_val, char* to_val, int notificationFlag) {
	char* output;
	char* notFlagChars;
	char* fromValLenChars;
	char* toValLenChars;
	char* packageEndWithSlash;
	char* packageEnd;
	packageEndWithSlash = strrchr(package, '/');
	packageEnd = malloc(strlen(packageEndWithSlash) - 1);
	strcpy(packageEnd, packageEndWithSlash + 1);
	output = malloc(strlen(hf_type) + strlen(package)
			+ strlen(row_name) + strlen(attr_name)
			+ strlen(from_val) + strlen(to_val) + 32);
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
	strcat(output, row_name);
	strcat(output, ",");
	strcat(output, attr_name);
	strcat(output, ",");
	fromValLenChars = malloc(16);
	sprintf(fromValLenChars, "%d", strlen(from_val));
	strcat(output, fromValLenChars);
	strcat(output, ",");
	strcat(output, from_val);
	strcat(output, ",");
	strcat(output, to_val);
	strcat(output, "\n");
	return output;
}
