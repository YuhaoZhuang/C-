#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"



int main(int argc, char* argv[]) {
	
	FILE *fp;
	struct matrix newmatrix = {};

	fp = fopen(argv[1], "r");
	fscanf(fp, "%d ", &newmatrix.size);
	fscanf(fp, "%d ", &newmatrix.size);

	newmatrix.m = (double**)malloc(newmatrix.size * sizeof(double*));
	for (int i = 0; i < newmatrix.size; i++) {
		newmatrix.m[i] = (double*)malloc(newmatrix.size * sizeof(double));
	}

	for (int i = 0; i < newmatrix.size; i++) {
		for (int j = 0; j < newmatrix.size; j++) {
			newmatrix.m[i] = (double*)realloc(newmatrix.m[i], (newmatrix.size) * sizeof(double));
			fscanf(fp, "%lf ", &newmatrix.m[i][j]);
		}
	}




	double answer = cal(newmatrix);

	for (int d = 0; d < newmatrix.size; d++) {
		free(newmatrix.m[d]);
	}

	free(newmatrix.m);
	printf("The determinant is %.2lf.", answer);

	
	return 0;

}