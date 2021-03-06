#include "StructMatrix.h"

void viterbi_log(struct Matrix mat_class, double Test_Vect[], int X[], double *Pvit){

	/*
	// working example
	double A_Vect[5][5] =
	{ { 1e-200, 1.0000, 1e-200, 1e-200, 1e-200 },
	{ 1e-200, 0.9091, 0.0909, 1e-200, 1e-200 },
	{ 1e-200, 1e-200, 0.9524, 0.0476, 1e-200 },
	{ 1e-200, 1e-200, 1e-200, 0.9091, 0.0909 },
	{ 1e-200, 1e-200, 1e-200, 1e-200, 1e-200 } };

	double Mu_Vect[3][5][7] =
	{ { { 1e-200, 1e-200, 1e-200, 1e-200, 1e-200, 1e-200, 1e-200 },
	{ -0.1823, -0.1318, -0.1882, -0.1314, -0.1312, -0.1316, -0.1576 },
	{ 0.3723, 0.5021, 0.2999, 0.1289, 0.1214, 0.4308, 0.0754 },
	{ -0.1445, -0.0517, -0.0003, -0.0816, -0.1828, -0.0816, -0.1059 },
	{ 1e-200, 1e-200, 1e-200, 1e-200, 1e-200, 1e-200, 1e-200 } },
	{ { 1e-200, 1e-200, 1e-200, 1e-200, 1e-200, 1e-200, 1e-200 },
	{ -0.1991, -0.1967, -0.1995, -0.1967, -0.1966, -0.1967, -0.1982 },
	{ -0.0347, -0.0108, -0.0490, -0.1344, -0.0358, -0.0142, -0.1769 },
	{ -0.1748, -0.2022, -0.1975, -0.1978, -0.1556, -0.1978, -0.1909 },
	{ 1e-200, 1e-200, 1e-200, 1e-200, 1e-200, 1e-200, 1e-200 } },
	{ { 1e-200, 1e-200, 1e-200, 1e-200, 1e-200, 1e-200, 1e-200 },
	{ 0.5494, 0.5837, 0.5457, 0.5838, 0.5839, 0.5838, 0.5675 },
	{ -1.1087, -1.9749, -0.6158, 0.3536, -0.2401, -1.6184, 0.9421 },
	{ 0.8412, 0.9949, 1.0627, 0.9490, 0.7782, 0.9490, 0.9073 },
	{ 1e-200, 1e-200, 1e-200, 1e-200, 1e-200, 1e-200, 1e-200 } } };

	double Sigma_Vect[3][5][7] =
	{ { { 1e-200, 1e-200, 1e-200, 1e-200, 1e-200, 1e-200, 1e-200 },
	{ 0.0100, 0.0100, 0.0100, 0.0100, 0.0100, 0.0100, 0.0100 },
	{ 0.0828, 0.0308, 0.0890, 0.1311, 0.0100, 0.0607, 0.0278 },
	{ 0.0138, 0.0100, 0.0139, 0.0100, 0.0100, 0.0100, 0.0100 },
	{ 1e-200, 1e-200, 1e-200, 1e-200, 1e-200, 1e-200, 1e-200 } },
	{ { 1e-200, 1e-200, 1e-200, 1e-200, 1e-200, 1e-200, 1e-200 },
	{ 0.0100, 0.0100, 0.0100, 0.0100, 0.0100, 0.0100, 0.0100 },
	{ 0.0533, 0.0122, 0.0578, 0.0235, 0.0100, 0.0330, 0.0100 },
	{ 0.0100, 0.0100, 0.0100, 0.0100, 0.0100, 0.0100, 0.0100 },
	{ 1e-200, 1e-200, 1e-200, 1e-200, 1e-200, 1e-200, 1e-200 } },
	{ { 1e-200, 1e-200, 1e-200, 1e-200, 1e-200, 1e-200, 1e-200 },
	{ 0.0100, 0.0100, 0.0100, 0.0100, 0.0100, 0.0100, 0.0100 },
	{ 0.0942, 0.0689, 0.1170, 0.2300, 0.0100, 0.1122, 0.0740 },
	{ 0.0238, 0.0100, 0.0101, 0.0100, 0.0111, 0.0100, 0.0100 },
	{ 1e-200, 1e-200, 1e-200, 1e-200, 1e-200, 1e-200, 1e-200 } } };

	double PComp_Vect[5][7] =
	{ { 1e-200, 1e-200, 1e-200, 1e-200, 1e-200, 1e-200, 1e-200 },
	{ 0.6163, 0.0440, 0.0001, 0.0415, 0.0395, 0.0429, 0.2157 },
	{ 0.0952, 0.2359, 0.0953, 0.2388, 0.0476, 0.1451, 0.1421 },
	{ 0.2728, 0.0909, 0.2726, 0.0350, 0.1819, 0.0559, 0.0909 },
	{ 1e-200, 1e-200, 1e-200, 1e-200, 1e-200, 1e-200, 1e-200 } };

	double Test_Vect2[3][40] =
	{ { -0.0020, -0.0001, 0.0021, 0.0058, 0.0103, 0.0178, 0.0324, 0.0642, 0.1136, 0.2039, 0.2956, 0.3922, 0.4920, 0.5506, 0.6016, 0.6376, 0.6599, 0.6744, 0.6682, 0.6184, 0.5574, 0.5010, 0.4430, 0.4059, 0.3827, 0.3699, 0.3606, 0.3501, 0.3428, 0.3395, 0.3364, 0.3307, 0.3211, 0.3095, 0.2921, 0.2727, 0.2517, 0.2327, 0.2156, 0.1986 },
	{ -0.2618, -0.2615, -0.2611, -0.2609, -0.2604, -0.2591, -0.2559, -0.2458, -0.2230, -0.1908, -0.1653, -0.1332, -0.1035, -0.0842, -0.0754, -0.0740, -0.0718, -0.0729, -0.0975, -0.1220, -0.1459, -0.1738, -0.1884, -0.1975, -0.2085, -0.2163, -0.2232, -0.2289, -0.2348, -0.2399, -0.2438, -0.2464, -0.2477, -0.2485, -0.2484, -0.2475, -0.2458, -0.2436, -0.2412, -0.2384 },
	{ 0.5527, 0.5531, 0.5537, 0.5547, 0.5548, 0.5495, 0.5199, 0.4280, 0.2207, -0.1488, -0.5688, -0.9862, -1.3932, -1.6217, -1.8363, -1.9831, -2.0717, -2.1266, -2.0999, -1.7792, -1.3274, -0.7748, -0.2202, 0.2289, 0.5405, 0.7298, 0.8556, 0.9403, 0.9892, 1.0054, 0.9949, 0.9699, 0.9377, 0.9058, 0.8755, 0.8475, 0.8214, 0.7984, 0.7782, 0.7587 } };
	*/
	
	double A_Vect[N][N];
	double Mu_Vect[D][N][K];
	double Sigma_Vect[D][N][K];
	double PComp_Vect[N][K];
		
	memcpy(A_Vect, mat_class.A, N*N*sizeof(double));
	memcpy(Mu_Vect, mat_class.MU, D*N*K*sizeof(double));
	memcpy(Sigma_Vect, mat_class.SIGMA, D*N*K*sizeof(double));
	memcpy(PComp_Vect, mat_class.PComp, N*K*sizeof(double));
	
	double *LogPdf = calloc(T*(N - 2),sizeof(double));

	for (int n = 1; n < N - 1; n++){

		double * Mu_Vect_Array = malloc(D*K*sizeof(double));
		double * Sigma_Vect_Array = malloc(D*K*sizeof(double));
		double * Test_Vect_Array = malloc(D*T*sizeof(double));
		double * PComp_Vect_Array = malloc(K*sizeof(double));
		
		for (int d = 0; d < D; d++){
			for (int k = 0; k < K; k++){
				Mu_Vect_Array[k + d*K] = Mu_Vect[d][n][k];
				Sigma_Vect_Array[k + d*K] = Sigma_Vect[d][n][k];
			}
			for (int t = 0; t < T; t++)
				//Test_Vect_Array[t + d*T] = Test_Vect2[d][t];
				Test_Vect_Array[t + d*T] = Test_Vect[t + d*T];
		}
		for (int k = 0; k < K; k++)
			PComp_Vect_Array[k] = PComp_Vect[n][k];

		// compute the distribution
		double * Log = wdensity(Mu_Vect_Array, Sigma_Vect_Array, PComp_Vect_Array, Test_Vect_Array);

		// de-alloc the memory
		free(Mu_Vect_Array);
		free(Sigma_Vect_Array);
		free(Test_Vect_Array);
		free(PComp_Vect_Array);

		for (int t = 0; t < T; t++)
			LogPdf[t + (n - 1)*T] = Log[t];

		// de-alloc the memory
		free(Log);
	}


	double * A_Vect_Array = malloc(N*N*sizeof(double));
	for (int n1 = 0; n1 < N ; n1++)
		for (int n2 = 0; n2 < N ; n2++)
			A_Vect_Array[n1 + n2*N] = A_Vect[n1][n2];
		
	
	double * FI = calloc(N*T,sizeof(double));
	int * XX = calloc(N*T, sizeof(int));

	viterbi_init(FI, A_Vect_Array, LogPdf);
	viterbi_cycle(FI, XX, A_Vect_Array, LogPdf);
	viterbi_end(FI, XX, A_Vect_Array, LogPdf, Pvit);

	free(LogPdf);

	// backtrace of states and probabilities
	X[T - 1] = XX[N*T - 1];
	//Prob[T - 1] = log(A_Vect_Array[X[T - 1]+ N*(N-1)]);  
	for (int t = T - 2; t > -1; t--){
		X[t] = XX[(t+1)*N+X[(t+1)]-1];
		//Prob[t] = log(A_Vect_Array[X[t] -1 + N*(X[t+1] - 1)]);
	}

	free(A_Vect_Array);
	free(FI);
	free(XX);
	
}