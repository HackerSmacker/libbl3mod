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
	output = malloc(strlen(name) + strlen(comment) +
		strlen(author) + strlen(version) + 50);
	strcat(output, "###\n");
	strcat(output, "### Name: ");
	strcat(output, name);
	strcat(output, "\n### Version: ");
	strcat(output, version);
	strcat(output, "\n### Author: ");
	strcat(output, author);
	strcat(output, "\n### Comment: ");
	strcat(output, comment);
	strcat(output, "\n");
	return output;
}

