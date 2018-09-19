#include "reverse.h"
#include "file_utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>


int main (int argc, char** argv) {
	if (argc != 3) {
		fprintf(stderr, "Invalid Number of Parameters\n");
		return EPERM;
	}

	char* file_buffer = NULL;
	
	char* input_file = argv[1];

	char* output_file = argv[2];


	int file_size = read_file(input_file, &file_buffer);
	if ( file_size < 0 ) {
		fprintf(stderr, "Error Loading Input File");

		return EIO;
	}


	reverse_text(&file_buffer, file_size);

	if(write_file(output_file, file_buffer, file_size) == -1){
		fprintf(stderr, "Error Writing Output File");
		
		return EIO;
	}

	free(file_buffer);
	return 0;
}

void reverse_text(char** contents, int file_size) {
	char* reversed_contents = (char*) 
		malloc((file_size - 1) * sizeof(char));

	for( int index = file_size - 1; index >= 0; index-- ) {
		*(reversed_contents + file_size - 1 - index) 
			= *(*contents + index);
	}

	free(contents);

	*contents = reversed_contents
}

