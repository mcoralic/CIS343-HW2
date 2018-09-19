#include "file_utils.h"
#include <sys/stat.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>

int read_file( char* filename, char **buffer ){
	int size;
	FILE* input_file = fopen(filename, "r");

	if(input_file) {
		struct stat st;
		stat(filename, &st);
		size = st.st_size;

		*buffer = (char*) malloc(size * sizeof(char));

		char ch = 0;
		int index = 0;

		ch = fgetc(input_file);
		while(ch != EOF){
			*(*buffer + index) = ch;
			ch = fgetc(input_file);
			++index;

		}

		fclose(input_file);
	}

	else {
		size = -1;
	}

	return size;
}

	int write_file( char* filename, char *buffer, int size ){
		FILE* output_file = fopen(filename, "w");
		int status = 1;

		if(output_file){
			for(int index = 0; index < size; ++index){
				fputc(buffer[index], output_file);
			}
		}
		else {
			status = -1;
		}

		fclose(output_file);
		return status;
	}
