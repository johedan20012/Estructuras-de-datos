#ifndef FileManager_H
#define FileManager_H

#include <stdio.h>
#include <stdlib.h>

void readStringFromFile(char ** Buffer,const char* file_path) {
	FILE* file = fopen(file_path, "rb");

	if (file){
		fseek(file, 0, SEEK_END);
		long int length = ftell(file);
		fseek(file, 0, SEEK_SET);
		*(Buffer) = (char*) malloc(length+1);
		if (*Buffer){
			fread(*Buffer, 1, length, file);
			*((*Buffer) + length) = '\0';
		}
		fclose(file);
		return;
	}

	printf("No se puedo abrir el fichero %s", file_path);
}


#endif