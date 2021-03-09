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


char* mesh_hotfix(const char* hf_type, char* pakFile, char* object,  
		char* attr_name, char* piece, char* to_val, int visible,
		int notificationFlag) {
	char* output;
	char* notFlagChars;
	char* visibleChars;
	char* toValLenChars;
	int size;
	size = (strlen(hf_type) + strlen(piece)
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
	strcat(output, object);
	strcat(output, ",");
	strcat(output, attr_name);
	strcat(output, ",");
	strcat(output, piece);
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

char* mesh_coord(char* x, char* y, char* z, char* rx,
		char* ry, char* rz, char* sx, char* sy, char* sz) {
	char* output;
	int len;
	len = (strlen(x) + strlen(y) + strlen(z) + strlen(rx)
			+ strlen(ry) + strlen(rz) + strlen(sx)
			+ strlen(sy) + strlen(sz) + 8);
	output = malloc(len);
	memset(output, 0x00, len);
	strcat(output, x);
	strcat(output, ",");
	strcat(output, y);
	strcat(output, ",");
	strcat(output, z);
	strcat(output, "|");
	strcat(output, rx);
	strcat(output, ",");
	strcat(output, ry);
	strcat(output, ",");
	strcat(output, rz);
	strcat(output, "|");
	strcat(output, sx);
	strcat(output, ",");
	strcat(output, sy);
	strcat(output, ",");
	strcat(output, sz);
	return output;
}
