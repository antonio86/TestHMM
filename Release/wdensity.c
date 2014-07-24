#include <math.h>
#include "StructMatrix.h"
#include "wdensity.h"
#include <stdlib.h>

#define PI 3.14159265358979323846

float * wdensity(float Mu_Vect[], float Sigma_Vect[], float PComp_Vect[], float Test_Vect[])
{

	// Parameter initialization
	float logDetSigma, mahalaD, maxll, temp;
	int k, t, d;
	float *LOG = malloc(T * K * sizeof(float));
	float *LOG_Array = malloc(T * K* sizeof(float));
	float *LOGPDF = calloc(T, sizeof(float));

	// first cycle
	for (k = 0; k < K; k++)
	{

		logDetSigma = 0.0;

		for (d = 0; d < D; d++){
			logDetSigma += log(Sigma_Vect[k + d*K] * Sigma_Vect[k + d*K]);
		}
		
		double xx = Sigma_Vect[k + d*K];

		for (t = 0; t < T; t++)
		{
			mahalaD = 0.0;
			for (d = 0; d < D; d++){
				temp = (Test_Vect[t + d*T] - Mu_Vect[k + d*K]) / (Sigma_Vect[k + d*K]);
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
