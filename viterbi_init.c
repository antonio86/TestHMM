#include "math.h"
#include "StructMatrix.h"

#define T 40

void viterbi_init(double FI[], double A_Vect[], double LogPdf[]){

	for (int n = 1; n < (N - 1); n++){
		double s = A_Vect[n*N];
		double s2 = LogPdf[(n-1)*T];
		FI[n] = log(A_Vect[n*N]) + LogPdf[(n - 1)*T];
	}
	return;
}