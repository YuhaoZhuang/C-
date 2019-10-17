#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


double cal(struct matrix newmatrix) {
	double output =0;
	if (newmatrix.size > 2) {
		for (int s = 0; s<newmatrix.size; s++) {
			struct matrix a = {};
			a.size = newmatrix.size - 1;
			a.m = (double**)malloc(a.size * sizeof(double*));
			for (int i = 0; i < a.size; i++) {
				a.m[i] = (double*)malloc(a.size * sizeof(double));
			}
			for (int w = 0; w < a.size; w++) {

				int keep1 = 0;
				for (int w1 = 0; w1<a.size; w1++) {
					a.m[w] = (double*)realloc(a.m[w], a.size * sizeof(double));
					if (s == w1) {
						keep1 += 1;
					}
					a.m[w][w1] = newmatrix.m[w+1][keep1];
					keep1 += 1;
				}	

			}
			if (s % 2 != 0) {
				output -= (newmatrix.m[0][s]) * (cal(a));
				
				for (int lol = 0; lol < a.size; lol++) {
					free(a.m[lol]);
				}
				free(a.m);
			}
			else {
				output += (newmatrix.m[0][s]) * (cal(a));
				
				for (int lol = 0; lol < a.size; lol++) {
					free(a.m[lol]);
				}
				free(a.m);
			}
		}
		return output;


	}
	else {
		double a = newmatrix.m[0][0];
		double b = newmatrix.m[0][1];
		double c = newmatrix.m[1][1];
		double d = newmatrix.m[1][0];
		output = (a*c) - (b*d);
		return output;
	}
	
}