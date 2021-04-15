/*
	libbl3hotfixmod
	(c) 2021 HackerSmacker
	Licensed under the terms of the GPLv3 license

	header.c
*/

#include <string.h>
#include <stdlib.h>
#include "bl3mod.h"

char* mod_header(char* name, char* author, char* comment, char* version) {
	char* output;
	int len;
	len = (strlen(name) + strlen(comment) +
		strlen(author) + strlen(version) + 50);
	output = malloc(len);
	#ifdef OLDCOMPILER
	bzero(output, len);
	#else
	memset(output, 0x00, len);
	#endif
	strcat(output, "###\n");
	strcat(output, "### Name: ");
	strcat(output, name);
	strcat(output, "\n### Version: ");
	strcat(output, version);
	strcat(output, "\n### Author: ");
	strcat(output, author);
	strcat(output, "\n### Comment: ");
	strcat(output, comment);
	strcat(output, "\n###\n");
	return output;
}

