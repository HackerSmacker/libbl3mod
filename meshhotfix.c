#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "bl3mod.h"

/* LIBBL3MOD SYSTEM CODE: LICENSED UNDER THE TERMS OF THE GPLV3 LICENSE. */
/* FAILURE TO COMPLY WITH THE LICENSE TERMS */
/* SPECIFIED WILL RESULT IN CONSEQUENCES. */

char* mesh_hotfix(const char* hf_type, char* pakFile, char* map,  
		char* objClass, char* obj, char* to_val, int visible,
		int notificationFlag) {
	char* output;
	char* notFlagChars;
	char* visibleChars;
	char* toValLenChars;
	int size;
	size = (strlen(hf_type)
			+ strlen(objClass)
			+ strlen(pakFile)
			+ strlen(to_val)
			+ strlen(map)
			+ strlen(obj)
			+ 32);
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
	strcat(output, map);
	strcat(output, ",");
	strcat(output, objClass);
	strcat(output, ",");
	strcat(output, obj);
	strcat(output, ",");
	toValLenChars = malloc(8);
	memset(toValLenChars, 0x00, 8);
	sprintf(toValLenChars, "%d", strlen(to_val));
	strcat(output, toValLenChars);
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
