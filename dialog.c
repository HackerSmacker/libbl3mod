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
	int loopContinue = 1;
	printf("BL3 Hotfix Mod \"GUI\"\n");
	printf("(c) 2021 HackerSmacker\n");
	printf("Output file? ");
	outputFile = malloc(1024);
	memset(outputFile, 0x00, 1024);
	fgets(outputFile, 1024, stdin);
	strtok(outputFile, "\n");
	printf("Will use %s.\n", outputFile);
	outFile = fopen(outputFile, "w");
	if(!outFile) {
		printf("Error! Cannot open output file! Exiting...\n");
		exit(-1);
	}
	printf("Please answer the following questions for the mod header.\n");
	printf("Name of your mod: ");
	header_name = malloc(1024);
	memset(header_name, 0x00, 1024);
	fgets(header_name, 1024, stdin);
	strtok(header_name, "\n");
	printf("Your name: ");
	header_author = malloc(1024);
	memset(header_author, 0x00, 1024);
	fgets(header_author, 1024, stdin);
	strtok(header_author, "\n");
	printf("A description for your mod: ");
	header_comments = malloc(1024);
	memset(header_comments, 0x00, 1024);
	fgets(header_comments, 1024, stdin);
	strtok(header_comments, "\n");
	printf("Mod version: ");
	header_version = malloc(1024);
	memset(header_version, 0x00, 1024);
	fgets(header_version, 1024, stdin);
	strtok(header_version, "\n");
	header = mod_header(header_name, header_author,
			header_comments, header_version);
	fwrite(header, sizeof(char), strlen(header), outFile);
	printf("To exit, enter X\n");
	while(loopContinue == 1) {
		printf("Mod Choices\n");
		printf("1 - Regular hotfix\n");
		printf("2 - Table hotfix\n");
		printf("3 - Level geometry hotfix\n");
		printf("X - Exit\n");
		choice = malloc(32);
		memset(choice, 0x00, 32);
		fgets(choice, 32, stdin);
		strtok(choice, "\n");
		if(strcmp(choice, "3") == 0) {
			printf("Level geometry hotfix.\n");
			printf("What package is the map in? ");
			level_package = malloc(1024);
			memset(level_package, 0x00, 1024);
			fgets(level_package, 1024, stdin);
			strtok(level_package, "\n");
			printf("What is the path to the level? ");
			level_object = malloc(1024);
                        memset(level_object, 0x00, 1024);
                        fgets(level_object, 1024, stdin);
                        strtok(level_object, "\n");
			printf("What object in the level are you modifying? ");
			level_part = malloc(1024);
                        memset(level_part, 0x00, 1024);
                        fgets(level_part, 1024, stdin);
                        strtok(level_part, "\n");
			printf("New X coordinate: ");
			level_x = malloc(1024);
                        memset(level_x, 0x00, 1024);
                        fgets(level_x, 1024, stdin);
                        strtok(level_x, "\n");
			printf("New Y coordinate: ");
                        level_y = malloc(1024);
                        memset(level_y, 0x00, 1024);
                        fgets(level_y, 1024, stdin);
                        strtok(level_y, "\n");
			printf("New Z coordinate: ");
                        level_z = malloc(1024);
                        memset(level_z, 0x00, 1024);
                        fgets(level_z, 1024, stdin);
                        strtok(level_z, "\n");
			printf("New X rotation: ");
                        level_rx = malloc(1024);
                        memset(level_rx, 0x00, 1024);
                        fgets(level_rx, 1024, stdin);
                        strtok(level_rx, "\n");
			printf("New Y rotation: ");
                        level_ry = malloc(1024);
                        memset(level_ry, 0x00, 1024);
                        fgets(level_ry, 1024, stdin);
                        strtok(level_ry, "\n");
			printf("New Z rotation: ");
                        level_rz = malloc(1024);
                        memset(level_rz, 0x00, 1024);
                        fgets(level_rz, 1024, stdin);
                        strtok(level_rz, "\n");
			printf("New X scale: ");
                        level_sx = malloc(1024);
                        memset(level_sx, 0x00, 1024);
                        fgets(level_sx, 1024, stdin);
                        strtok(level_sx, "\n");
			printf("New Y scale: ");
                        level_sy = malloc(1024);
                        memset(level_sy, 0x00, 1024);
                        fgets(level_sy, 1024, stdin);
                        strtok(level_sy, "\n");
			printf("New Z scale: ");
                        level_sz = malloc(1024);
                        memset(level_sz, 0x00, 1024);
                        fgets(level_sz, 1024, stdin);
                        strtok(level_sz, "\n");
			level_toval = mesh_coord(level_x, level_y, level_z,
					level_rx, level_ry, level_rz,
					level_sx, level_sy, level_sz);
			output = mesh_hotfix(mod_type_earlylevel,
					level_package,
					level_object,
					level_part,
					level_toval,
					0,
					0);
			fwrite(output, sizeof(char), strlen(output), outFile);
		}
		else if(strcmp(choice, "X")) {
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
