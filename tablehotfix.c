#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "bl3mod.h"

char* table_hotfix_adv(const char* hf_type, char* pakFile,
		char* object, char* row_name, char* attr_name, 
		char* from_val, char* to_val, int notificationFlag) {
	char* output;
	char* notFlagChars;
	char* fromValLenChars;
	char* toValLenChars;
	int size;
	size = (strlen(hf_type) + strlen(object)
			+ strlen(row_name) + strlen(attr_name)
			+ strlen(from_val) + strlen(to_val) + 32);
	output = malloc(size);
	memset(output, 0x00, size);
	strcat(output, hf_type);
	strcat(output, ",");
	strcat(output, "(1,2,");
	notFlagChars = malloc(2);
	sprintf(notFlagChars, "%d", notificationFlag);
	strcat(output, notFlagChars);
	strcat(output, ",");
	strcat(output, pakFile);
	strcat(output, "),");
	strcat(output, object);
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

char* table_hotfix(const char* hf_type, char* object,  
		char* row_name, char* attr_name, 
		char* to_val, int notificationFlag) {
	char* output;
	char* notFlagChars;
	char* toValLenChars;
	int size;
	size = (strlen(hf_type) 
			+ strlen(object)
			+ strlen(row_name)
			+ strlen(attr_name)
			+ strlen(to_val)
			+ 32);
	output = malloc(size);
	memset(output, 0x00, size);
	strcat(output, hf_type);
	strcat(output, ",");
	strcat(output, "(1,2,");
	notFlagChars = malloc(2);
	sprintf(notFlagChars, "%d", notificationFlag);
	strcat(output, notFlagChars);
	strcat(output, ",),");
	strcat(output, object);
	strcat(output, ",");
	strcat(output, row_name);
	strcat(output, ",");
	strcat(output, attr_name);
	strcat(output, ",0,,");
	strcat(output, to_val);
	strcat(output, "\n");
	return output;
}

char* table_hotfix_matchall(const char* hf_type, char* object,  
		char* row_name, char* attr_name, 
		char* to_val, int notificationFlag) {
	char* output;
	char* notFlagChars;
	char* toValLenChars;
	int size;
	size = (strlen(hf_type) 
			+ strlen(object)
			+ strlen(row_name)
			+ strlen(attr_name)
			+ strlen(to_val)
			+ 32);
	output = malloc(size);
	memset(output, 0x00, size);
	strcat(output, hf_type);
	strcat(output, ",");
	strcat(output, "(1,2,");
	notFlagChars = malloc(2);
	sprintf(notFlagChars, "%d", notificationFlag);
	strcat(output, notFlagChars);
	strcat(output, ",MatchAll),");
	strcat(output, object);
	strcat(output, ",");
	strcat(output, row_name);
	strcat(output, ",");
	strcat(output, attr_name);
	strcat(output, ",0,,");
	strcat(output, to_val);
	strcat(output, "\n");
	return output;
}
