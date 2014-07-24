#include <stdlib.h>
#include <string.h>

#include <math.h>
#include "StructMatrix.h"

#define DBL_MAX 1.79769e+308

void maxx(float Ar[], int dim, float *val, int *pos){

	*val = -DBL_MAX;
	*pos = 0;
	int n;
	for (n = 0; n < dim; n++){
		if (Ar[n] > *val){
			*val = Ar[n];
			*pos = n;
		}

	}
}

void viterbi_end(float FI[], int XX[], float A_Vect[], float LogPdf[], float *Pvit){

	// end of viterbi
	float temp[N-2];
	int n;
	for (n = 1; n < (N - 1); n++)
		temp[n - 1] = FI[(T - 1)*N + n] + log(A_Vect[(N - 1)*N + n]);


	// Allocation of memory
	float *max_val = malloc(sizeof(float));
	int *max_pos = malloc(sizeof(int));
	maxx(temp, N-2, max_val, max_pos);

	*Pvit = *max_val;

	XX[N*T - 1] = *max_pos + 2;

	// de-allocation of memory
	free(max_val);
	free(max_pos);
	return;
}
