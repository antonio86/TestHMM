#include <math.h>
#include "StructMatrix.h"
#include <stdlib.h>

#define PI 3.14159265358979323846

double * wdensity(double Mu_Vect[], double Sigma_Vect[], double PComp_Vect[], double Test_Vect[])
{

	// Parameter initialization
	double logDetSigma, mahalaD, maxll, temp;
	int k, t, n;
	double *LOG = malloc(T * K * sizeof(double));
	double *LOG_Array = malloc(T * K* sizeof(double));
	double *LOGPDF = calloc(T, sizeof(double));

	// first cycle
	for (k = 0; k < K; k++)
	{

		logDetSigma = 0.0;

		for (n = 0; n < N; n++)
			logDetSigma += log(Sigma_Vect[k + n*K] * Sigma_Vect[k + n*K]);
		
		for (t = 0; t < T; t++)
		{
			mahalaD = 0.0;
			for (n = 0; n < N; n++){
				temp = (Test_Vect[t + n*T] - Mu_Vect[k + n*K]) / (Sigma_Vect[k + n*K]);
				mahalaD += temp*temp;
			}
			LOG[t + k*T] = -0.5*(mahalaD + logDetSigma) + log(PComp_Vect[k]) - N*log(2 * PI) / 2;
		}

	}

	// second cycle
	for (t = 0; t < T; t++)
	{
		maxll = LOG[t];
		for (k = 1; k < K; k++)
			if (LOG[t + k*T] > maxll)
				maxll = LOG[t + k*T];

		for (k = 0; k < K; k++)
			LOGPDF[t] += exp((LOG[t + k*T] - maxll));

		LOGPDF[t] = log(LOGPDF[t]) + maxll;
		
	}

	// free the memory
	free(LOG);
	free(LOG_Array);
	return LOGPDF;

}