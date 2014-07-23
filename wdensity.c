#include <math.h>
#include "StructMatrix.h"
#include <stdlib.h>

#define PI 3.14159265358979323846
#define M 40
#define K 7
#define N 3

double * wdensity(double Mu_Vect[], double Sigma_Vect[], double PComp_Vect[], double Test_Vect[])
{

	// Macros for the ouput and input arguments 

	double logDetSigma, mahalaD, maxll, temp;
	int k, m, n;

	double *LOG = malloc(M * K * sizeof(double));

	double *LOG_Array = malloc(M * K* sizeof(double));

	double *LOGPDF = calloc(M, sizeof(double));


	for (k = 0; k < K; k++)
	{

		logDetSigma = 0.0;

		for (n = 0; n < N; n++)
			logDetSigma += log(Sigma_Vect[k + n*K] * Sigma_Vect[k + n*K]);
		
		for (m = 0; m < M; m++)
		{
			mahalaD = 0.0;

			for (n = 0; n < N; n++){
				temp = (Test_Vect[m + n*M] - Mu_Vect[k + n*K]) / (Sigma_Vect[k + n*K]);
				mahalaD += temp*temp;
			}

			LOG[m + k*M] = -0.5*(mahalaD + logDetSigma) + log(PComp_Vect[k]) - N*log(2 * PI) / 2;
			double x = LOG[m + k*M];
			int f = 0;
			
		}

	}

	for (m = 0; m < M; m++)
	{
		maxll = LOG[m];
		for (k = 1; k < K; k++)
		if (LOG[m + k*M] > maxll)
			maxll = LOG[m + k*M];

		for (k = 0; k < K; k++)
			LOGPDF[m] += exp((LOG[m + k*M] - maxll));

		LOGPDF[m] = log(LOGPDF[m]) + maxll;
		double xxx3 = LOGPDF[m];
		int f2 = 0;
		
	}

	free(LOG);
	free(LOG_Array);
	return LOGPDF;

}