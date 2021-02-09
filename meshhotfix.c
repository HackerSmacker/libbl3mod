#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "bl3mod.h"

/*
 * 1. Package
 * 2. Object name (i.e. map name)
 * 3. Level object
 * 4. Length of the next field
 * 5. "x,y,z|p,y,w|sx,sy,sz" (location, rotation, scale)
 * 6. Visibility
 */


char* mesh_hotfix(const char* hf_type, char* pakFile, char* package,  
		char* attr_name, char* object, char* to_val, int visible,
		int notificationFlag) {
	char* output;
	char* notFlagChars;
	char* visibleChars;
	char* toValLenChars;
	int size;
	size = (strlen(hf_type) + strlen(package)
			+ strlen(attr_name) + strlen(pakFile)
			+ strlen(to_val) + strlen(object) + 32);
	output = malloc(size);
	memset(output, 0x00, size);
	strcat(output, hf_type);
	strcat(output, ",");
	strcat(output, "(1,6,");
	notFlagChars = malloc(2);
	sprintf(notFlagChars, "%d", notificationFlag);
	strcat(output, notFlagChars);
	strcat(output, ",");
	strcat(output, pakFile);
	strcat(output, "),");
	strcat(output, package);
	strcat(output, ",");
	strcat(output, attr_name);
	strcat(output, ",");
	strcat(output, object);
	strcat(output, ",\"");
	strcat(output, to_val);
	strcat(output, "\",");
	visibleChars = malloc(2);
	memset(visibleChars, 0x00, 2);
	sprintf(visibleChars, "%d", visible);
	strcat(output, visibleChars);
	strcat(output, "\n");
	return output;
}
