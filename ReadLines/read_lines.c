#include <stdio.h>
#include <stdlib.h>

#include "read_lines.h"

void read_lines(FILE* fp, char*** lines, int* num_lines)
{
	char s ;
	*lines = (char**)malloc(1 * sizeof(char*));
	(*lines)[0] = (char*)malloc(1 * sizeof(char));
	int i = 0;
	while (!feof(fp)) {
        fscanf(fp, "%c", &s);
		(*lines)[*num_lines][i] = s;
		i += 1;
		(*lines)[*num_lines] = (char*)realloc((*lines)[*num_lines], (i+1) * sizeof(char));
		if (s == '\n') {
			(*lines)[*num_lines][i] = '\0';
			*num_lines += 1;
			(*lines) = (char**)realloc(*lines, (*num_lines+2) * sizeof(char*));
			(*lines+*num_lines)[0] = (char*)malloc(1 * sizeof(char));
			i = 0;
		}		
	}
    *num_lines -= 1;
	
}	