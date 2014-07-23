#include "StructMatrix.h"
#include "randNumX.h"

int TestMatrix(struct Matrix * foo_mat, double Test_Vect[], int Align[], double Pvit_w[]){

	// parameter initialization
	int winner = -1;
	double max_prob = -1e200;

	for (int nC = 0; nC < NClasses; nC++){

		// charge a single struct
		struct Matrix mat_class = foo_mat[nC];

		// parameter initialization
		int *X = calloc(T, sizeof(int));
		double *Pvit = calloc(1, sizeof(double));

		// computation of the X and Prob vectors
		viterbi_log(mat_class, Test_Vect, X, Pvit);
		Pvit_w[nC] = *Pvit;
		
		// to avoid to stock all the results, save only the best
		if (*Pvit > max_prob){
			memcpy(Align, X, T*sizeof(int));
			winner = nC;
			max_prob = *Pvit;
		}

		// free the allocated memory
		free(X);
		free(Pvit);
	}

	// return the winner
	return winner;
}