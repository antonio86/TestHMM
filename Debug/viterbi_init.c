#include "math.h"
#include "StructMatrix.h"

void viterbi_init(double FI[], double A_Vect[], double LogPdf[]){

	// initiliazation of viterbi
	for (int n = 1; n < (N - 1); n++)
		FI[n] = log(A_Vect[n*N]) + LogPdf[(n - 1)*T];
	
	return;
}