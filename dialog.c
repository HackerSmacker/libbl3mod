#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include "bl3mod.h"
#include "bl3modtype.h"

/*
 * Example program for libbl3mod
 * Hotfix Mod Dialog-driven Editor
 * (c) 2021 HackerSmacker
 * Licensed under the terms of the GPLv3 license
 */

FILE* outFile;

/* Does this code already exist somewhere else? Probably! */

char* getVal() {
	char* value;
	value = malloc(1024);
	memset(value, 0x00, 1024);
	fgets(value, 1024, stdin);
	strtok(value, "\n");
	return value;
}

int main(int argc, char** argv) {
	char* outputFile;
	char* input;
	char* header_name;
	char* header_version;
	char* header_comments;
	char* header_author;
	char* header;
	char* choice;
	char* level_package;
	char* level_object;
	char* level_part;
	char* level_toval;
	char* level_x;
	char* level_y;
	char* level_z;
	char* level_rx;
	char* level_ry;
	char* level_rz;
	char* level_sx;
	char* level_sy;
	char* level_sz;
	char* output;
	char* from_val;
	char* to_val;
	char* attribute;
	char* row;
	int loopContinue = 1;
	printf("BL3 Hotfix Mod \"GUI\"\n");
	printf("(c) 2021 HackerSmacker\n");
	#ifdef CMS
	printf("Warning: you are running on VM/CMS.\n");
	printf("Input might not work properly if you defined\n");
	printf("your terminal to be a 3215.\n");
	#endif
	#ifdef VMS
	printf("Warning: you are running on VMS or OpenVMS.\n");
	printf("Please note that some functions might crash.\n");
	#endif
	#ifdef OS2
	printf("Warning: you are running on OS/2. If this was\n");
	printf("compiled with IBM C Set/2 or VisualAge C++, there is\n");
	printf("a good chance that the object search functions can\n");
	printf("crash your machine.\n");
	#endif
	printf("Output file? ");
	outputFile = getVal();
	printf("Will use %s.\n", outputFile);
	outFile = fopen(outputFile, "w");
	if(!outFile) {
		printf("Error! Cannot open output file! Exiting...\n");
		exit(-1);
	}
	printf("Please answer the following questions for the mod header.\n");
	printf("Name of your mod: ");
	header_name = getVal();
	printf("Your name: ");
	header_author = getVal();
	printf("A description for your mod: ");
	header_comments = getVal();
	printf("Mod version: ");
	header_version = getVal();
	header = mod_header(header_name, header_author,
			header_comments, header_version);
	fwrite(header, sizeof(char), strlen(header), outFile);
	fwrite("\n", sizeof(char), 1, outFile);
	printf("To exit, enter X\n");
	while(loopContinue == 1) {
		printf("Mod Choices\n");
		printf("1 - Regular hotfix\n");
		printf("2 - Table hotfix\n");
		printf("3 - Level geometry hotfix\n");
		printf("X - Exit\n");
		choice = getVal();
		if(strcmp(choice, "1") == 0) {
			printf("Regular hotfix.\n");
			printf("What package are you modifying? ");
			level_package = getVal();
			printf("What object are you modifying? ");
			level_object = getVal();
			printf("What attribute name are you modifying? ");
			attribute = getVal();
			printf("What is the \"from\" value? ");
			from_val = getVal();
			printf("What is the \"to\" value? ");
			to_val = getVal();
			output = regular_hotfix("SparkPatchEntry", level_package,
				level_object, attribute, from_val, to_val, 0);
			fwrite(output, sizeof(char), strlen(output), outFile);
		}
		else if(strcmp(choice, "2") == 0) {
			printf("Table hotfix.\n");
			printf("What package are you modifying? ");
			level_package = getVal();
			printf("What object are you modifying? ");
			level_object = getVal();
			printf("What attribute are you modifying? ");
			attribute = getVal();
			printf("What row name are you modifying? ");
			row = getVal();
			printf("What is the initial (from) value? ");
			from_val = getVal();
			printf("What is the new (to) value? ");
			to_val = getVal();
			output = table_hotfix("SparkPatchEntry", 
				level_object,
				attribute, row, from_val, to_val,
				0);
			// TODO: swap row and attribute because I think they're backwards
			fwrite(output, sizeof(char), strlen(output), outFile);
		}
		else if(strcmp(choice, "3") == 0) {
			printf("Level geometry hotfix.\n");
			printf("What package is the map in? ");
			level_package = getVal();
			printf("What is the path to the level? ");
			level_object = getVal();
			printf("What object in the level are you modifying? ");
			level_part = getVal();
			printf("New X coordinate: ");
			level_x = getVal();
			printf("New Y coordinate: ");
			level_y = getVal();
			printf("New Z coordinate: ");
			level_z = getVal();
			printf("New X rotation: ");
			level_rx = getVal();
			printf("New Y rotation: ");
			level_ry = getVal();
			printf("New Z rotation: ");
			level_rz = getVal();
			printf("New X scale: ");
			level_sx = getVal();
			printf("New Y scale: ");
			level_sy = getVal();
			printf("New Z scale: ");
			level_sz = getVal();
			level_toval = mesh_coord(level_x, level_y, level_z,
					level_rx, level_ry, level_rz,
					level_sx, level_sy, level_sz);
			/*
			output = mesh_hotfix(mod_type_earlylevel,
					level_package,
					level_object,
					level_part,
					level_toval,
					0,
			       		0);
			*/
			fwrite(output, sizeof(char), strlen(output), outFile);
		}
		else if(strcmp(choice, "X") == 0) {
			loopContinue = 0;
		}
		else {
			printf("Invalid choice.\n");
		}
	}


	printf("Execution complete\n");
	fclose(outFile);	
	return 0;
}
