#include "math.h"
#include "StructMatrix.h"
#include "viterbi_init.h"

void viterbi_init(float FI[], float A_Vect[], float LogPdf[]){

	// initiliazation of viterbi
	int n;
	for (n = 1; n < (N - 1); n++)
		FI[n] = log(A_Vect[n*N]) + LogPdf[(n - 1)*T];
	
	return;
}
