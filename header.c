/*
	libbl3hotfixmod
	(c) 2021 HackerSmacker
	Licensed under the terms of the GPLv3 license

	header.c
*/

/* Now with 100% less strcpy and strcat */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "bl3mod.h"

char* mod_header(char* name, char* author, char* comment, char* version) {
	char* output;
	int len = (strlen(name) + strlen(comment) +
		strlen(author) + strlen(version) + 50);
	output = malloc(len);
	#ifdef OLDCOMPILER
	bzero(output, len);
	#else
	memset(output, 0x00, len);
	#endif
	/*
	strcpy(output, "###\n");
	strcat(output, "### Name: ");
	strcat(output, name);
	strcat(output, "\n### Version: ");
	strcat(output, version);
	strcat(output, "\n### Author: ");
	strcat(output, author);
	strcat(output, "\n### Comment: ");
	strcat(output, comment);
	strcat(output, "\n");
	*/
	sprintf(output, "###\n### Name: %s\n### Version: %s\n### Author: %s\n### Comment: %s\n###\n",
		name, version, author, comment);
	return output;
}

char* mod_header_contact(char* type, char* address) {
	char* output;
	int len = strlen(type) + strlen(address) + 32;
	output = malloc(len);
	#ifdef OLDCOMPILER
	bzero(output, len);
	#else 
	memset(output, 0x00, len);
	#endif
	/*
	strcpy(output, "### Contact (");
	strcat(output, type);
	strcat(output, "): ");
	strcat(output, address);
	strcat(output, "\n");
	*/
	sprintf(output, "### Contact (%s): %s\n", type, address);
	return output;
}

char* mod_header_tags(char* tags) {
	char* output;
	int len = strlen(tags + 32);
	output = malloc(len);
	/*
	strcpy(output, "### Tags: ");
	strcat(output, tags);
	strcat(output, "\n");
	*/
	sprintf(output, "### Tags: %s\n", tags);
	return output;
}

char* mod_header_category(char* cats) {
        char* output;
        int len = strlen(cats + 32);
        output = malloc(len);
        sprintf(output, "### Category: %s\n", cats);
        return output;
}
