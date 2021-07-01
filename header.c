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

char* hdr_output;

char* header(char* name, char* author, char* comment, char* version) {
	int len = (strlen(name) + strlen(comment) +
		strlen(author) + strlen(version) + 50);
	hdr_output = malloc(len);
	#ifdef OLDCOMPILER
	bzero(hdr_output, len);
	#else
	memset(hdr_output, 0x00, len);
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
	sprintf(hdr_output, "###\n### Name: %s\n### Version: \
		%s\n### Author: %s\n### Comment: %s\n###\n",
		name, version, author, comment);
	return hdr_output;
}

char* header_acontact(char* type, char* address) {
	int len = strlen(type) + strlen(address) + 32;
	hdr_output = malloc(len);
	#ifdef OLDCOMPILER
	bzero(hdr_output, len);
	#else 
	memset(hdr_output, 0x00, len);
	#endif
	/*
	strcpy(output, "### Contact (");
	strcat(output, type);
	strcat(output, "): ");
	strcat(output, address);
	strcat(output, "\n");
	*/
	sprintf(hdr_output, "### Contact (%s): %s\n", type, address);
	return hdr_output;
}

char* header_tags(char* tags) {
	int len = strlen(tags + 32);
	hdr_output = malloc(len);
	/*
	strcpy(output, "### Tags: ");
	strcat(output, tags);
	strcat(output, "\n");
	*/
	sprintf(hdr_output, "### Tags: %s\n", tags);
	return hdr_output;
}

char* header_category(char* cats) {
        int len = strlen(cats + 32);
        hdr_output = malloc(len);
        sprintf(hdr_output, "### Category: %s\n", cats);
        return hdr_output;
}
