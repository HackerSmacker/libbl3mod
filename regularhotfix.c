#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "bl3mod.h"

char* regular_hotfix(const char* hf_type, char* pakFile, char* object,  
		char* attr_name, char* from_val, char* to_val, 
		int notificationFlag) {
	char* output;
	char* notFlagChars;
	char* fromValLenChars;
	char* toValLenChars;
	int size;
	size = (strlen(hf_type) + strlen(object)
			+ strlen(attr_name) + strlen(pakFile)
			+ strlen(from_val) + strlen(to_val) + 32);
	output = malloc(size);
	memset(output, 0x00, size);
	strcat(output, hf_type);
	strcat(output, ",");
	strcat(output, "(1,1,");
	notFlagChars = malloc(2);
	sprintf(notFlagChars, "%d", notificationFlag);
	strcat(output, notFlagChars);
	strcat(output, ",");
	strcat(output, pakFile);
	strcat(output, "),");
	strcat(output, object);
	strcat(output, ",");
	strcat(output, attr_name);
	strcat(output, ",");
	fromValLenChars = malloc(strlen(from_val));
	memset(fromValLenChars, 0x00, strlen(from_val));
	sprintf(fromValLenChars, "%d", strlen(from_val));
	strcat(output, fromValLenChars);
	strcat(output, ",");
	strcat(output, from_val);
	strcat(output, ",");
	strcat(output, to_val);
	strcat(output, "\n");
	return output;
}
