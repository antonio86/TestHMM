#include "StructMatrix.h"
#include "randNumX.h"

struct Matrix Learned[NClasses];

struct Matrix * LearnMatrix(void){

	for (int nC = 0; nC < NClasses; nC++){

		// Transition Matrix

		for (int n = 0; n < N; n++){
			// first column equal to zero
			Learned[nC].A[n][0] = 1e-200;
			// last row equal to zero
			Learned[nC].A[N][n] = 1e-200;
		}
		// cannot go from state 0 to end
		Learned[nC].A[N][N] = 1e-200;
	
		// first line
		float cumProb = 0.0;
		float randX = 0.0;
		for (int n = 1; n < N-2; n++){ 
			randX = randNumX(1 - cumProb);
			cumProb += randX;
			Learned[nC].A[0][n] = randX;
		}
		// for having 1 as total on the row	
		Learned[nC].A[0][N-2] = (1 - cumProb);

		// other lines
		for (int nj = 1; nj < N-1; nj++){
			cumProb = 0.0;
			for (int n = 1; n < N-1; n++){
				randX = randNumX(1 - cumProb);
				cumProb += randX;
				Learned[nC].A[nj][n] = randX;
			}
			// for having 1 as total on the row	
			Learned[nC].A[nj][N-1] = (1 - cumProb);
		}

		// Emission Matrix
		float MAX_MU = 2.0;
		float MAX_SIGMA = 3.0;

		// first and last colunm equal to zero
		for (int d = 0; d < D; d++){
				for (int k = 0; k < K; k++){
					Learned[nC].MU[d][0][k] = 0.0;
					Learned[nC].SIGMA[d][0][k] = 0.0;
					Learned[nC].MU[d][N][k] = 0.0;
					Learned[nC].SIGMA[d][N][k] = 0.0;
				}
		}

		// random values
		for (int d = 0; d < D; d++){
			for (int n = 1; n < N-1; n++){
				for (int k = 0; k < K; k++){
					Learned[nC].MU[d][n][k] = randNumX(MAX_MU) - MAX_MU/2;
					// always positive
					Learned[nC].SIGMA[d][n][k] = randNumX(MAX_SIGMA);
				}
			}
		}

		// Pcomp initialzated here
		for (int n = 0; n < N; n++){
			cumProb = 0.0;
			for (int k = 0; k < K-1; k++){
				randX = randNumX(1 - cumProb);
				cumProb += randX;
				Learned[nC].PComp[n][k] = randX;
			}
			// for having 1 as total on the row	
			Learned[nC].PComp[n][K - 1] = (1 - cumProb);
		}
		
	}

	////////////////////////////////
		

	return Learned;
}