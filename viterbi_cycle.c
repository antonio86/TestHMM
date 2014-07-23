#include "math.h"
#include "StructMatrix.h"

#define T 40

void viterbi_cycle(double FI[], int XX[], double A_Vect[], double LogPdf[]){

	double maxll, temp;
	int t, n1, n2, tpos;

	for (t = 1; t < T; t++)
	{
		for (n1 = 1; n1 < (N - 1); n1++)
		{
			tpos = 2;
			double g0 = FI[1 + (t - 1)*N];
			double g00 = A_Vect[1 + n1*N];
			maxll = FI[1 + (t - 1)*N] + log(A_Vect[1 + n1*N]);
			for (n2 = 2; n2 < (N - 1); n2++)
			{
				temp = FI[n2 + (t - 1)*N] + log(A_Vect[n2 + n1*N]);
				if (temp > maxll){
					maxll = temp;
					tpos = n2 + 1;
				}
			}

			XX[n1 + t*N] = tpos;
			FI[n1 + t*N] = maxll + LogPdf[t+(n1 - 1)*T];
			double g = tpos;
			double g2 = maxll;
			double g3 = LogPdf[t + (n1 - 1)*T];
			int f = 0;

		}
	}

	return;

}