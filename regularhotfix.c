#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "bl3mod.h"

// LIBBL3MOD SYSTEM CODE: LICENSED UNDER THE TERMS OF THE GPLV3 LICENSE.

char* regular_hotfix_adv(const char* hf_type,
			char* pakFile,
			char* object,
			char* attr,
			char* from_val,
			char* to_val,
			int notificationFlag) {
	char* output;
	char* notFlagChars;
	char* fromValLenChars;
	char* toValLenChars;
	int size;
	size = (strlen(hf_type) + strlen(object)
			+ strlen(attr) + strlen(pakFile)
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
	strcat(output, attr);
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

char* regular_hotfix(const char* hf_type,
				char* object,
                char* attr,
				char* to_val,
                int notificationFlag) {
	char* output;
	char* notFlagChars;
	int size;
	size = (strlen(hf_type)
			+ strlen(object)
			+ strlen(attr) 
			+ strlen(to_val) + 32);
	output = malloc(size);
	memset(output, 0x00, size);
	strcat(output, hf_type);
	strcat(output, ",(1,1,");
	notFlagChars = malloc(2);
	sprintf(notFlagChars, "%d", notificationFlag);
	strcat(output, notFlagChars);
	strcat(output, ",),");
	strcat(output, object);
	strcat(output, ",");
	strcat(output, attr);
	strcat(output, ",0,,");
	strcat(output, to_val);
	strcat(output, "\n");
	return output;
}

char* regular_hotfix_multi(const char* hf_type,
				char* object, 
                char* which,
				char* attr,
				char* to_val,
                int notificationFlag) {
	char* output;
	char* notFlagChars;
	int size;
	size = (strlen(hf_type)
			+ strlen(object)
			+ strlen(attr) 
			+ strlen(to_val) + 32);
	output = malloc(size);
	memset(output, 0x00, size);
	strcat(output, hf_type);
	strcat(output, ",(1,1,");
	notFlagChars = malloc(2);
	sprintf(notFlagChars, "%d", notificationFlag);
	strcat(output, notFlagChars);
	strcat(output, ",),");
	strcat(output, object);
	strcat(output, ":");
	strcat(output, which);
	strcat(output, ",");
	strcat(output, attr);
	strcat(output, ",0,,");
	strcat(output, to_val);
	strcat(output, "\n");
	return output;
}

char* regular_hotfix_field(const char* hf_type,
				char* object,
                char* attr,
				char* field,
				char* to_val,
                int notificationFlag) {
	char* output;
	char* notFlagChars;
	int size;
	size = (strlen(hf_type)
			+ strlen(object)
			+ strlen(attr) 
			+ strlen(to_val) + 32);
	output = malloc(size);
	memset(output, 0x00, size);
	strcat(output, hf_type);
	strcat(output, ",(1,1,");
	notFlagChars = malloc(2);
	sprintf(notFlagChars, "%d", notificationFlag);
	strcat(output, notFlagChars);
	strcat(output, ",),");
	strcat(output, object);
	strcat(output, ",");
	strcat(output, attr);
	strcat(output, ",0,,(");
	strcat(output, field);
	strcat(output, "=");
	strcat(output, to_val);
	strcat(output, ")\n");
	return output;
}

char* regular_hotfix_field_multi(const char* hf_type,
				char* object, 
                char* which,
				char* attr,
				char* field,
				char* to_val,
                int notificationFlag) {
	char* output;
	char* notFlagChars;
	int size;
	size = (strlen(hf_type)
			+ strlen(object)
			+ strlen(attr) 
			+ strlen(to_val) + 32);
	output = malloc(size);
	memset(output, 0x00, size);
	strcat(output, hf_type);
	strcat(output, ",(1,1,");
	notFlagChars = malloc(2);
	sprintf(notFlagChars, "%d", notificationFlag);
	strcat(output, notFlagChars);
	strcat(output, ",),");
	strcat(output, object);
	strcat(output, ":");
	strcat(output, which);
	strcat(output, ",");
	strcat(output, attr);
	strcat(output, ",0,,(");
	strcat(output, field);
	strcat(output, "=");
	strcat(output, to_val);
	strcat(output, ")\n");
	return output;
}

char* extract_object(char* object) {
	char* output;
	char* objEnd;
	objEnd = strrchr(object, '/');
	output = malloc(strlen(objEnd) - 1 + strlen(object));
	strcpy(output, object);
	strcat(output, ".");
	strcat(output, objEnd + 1);
	return output;
}

char* extract_object_c(char* object) {
	char* output;
	char* objEnd;
	objEnd = strrchr(object, '/');
	output = malloc(strlen(objEnd) - 1 + strlen(object));
	strcpy(output, object);
	strcat(output, ".");
	strcat(output, objEnd + 1);
	strcat(output, "_C");
	return output;
}