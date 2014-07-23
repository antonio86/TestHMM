#include <math.h>
#include "StructMatrix.h"

#define DBL_MAX 1.79769e+308

void maxx(double Ar[], int dim, double *val, int *pos){

	*val = -DBL_MAX;
	*pos = 0;
	for (int n = 0; n < dim; n++){
		if (Ar[n] > *val){
			*val = Ar[n];
			*pos = n;
		}

	}
}

void viterbi_end(double FI[], int XX[], double A_Vect[], double LogPdf[], double *Pvit){

	// end of viterbi
	double temp[N-2];
	for (int n = 1; n < (N - 1); n++)
		temp[n - 1] = FI[(T - 1)*N + n] + log(A_Vect[(N - 1)*N + n]);


	// Allocation of memory
	double *max_val = malloc(sizeof(double));
	int *max_pos = malloc(sizeof(int));
	maxx(temp, N-2, max_val, max_pos);

	*Pvit = *max_val;

	XX[N*T - 1] = *max_pos + 2;

	// de-allocation of memory
	free(max_val);
	free(max_pos);
	return;
}