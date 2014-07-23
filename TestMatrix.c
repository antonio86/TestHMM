#include "StructMatrix.h"
#include "randNumX.h"

#define T 40

int TestMatrix(struct Matrix * foo_mat, double Test_Vect[], int Align[], double Prob_vect[]){

	int winner = -1;
	double max_prob = -1e200;

	for (int nC = 0; nC < NClasses; nC++){

		// charge a single struct
		struct Matrix mat_class = foo_mat[nC];

		// parameter initialization
		int *X = calloc(T, sizeof(int));
		double *Prob = calloc(T, sizeof(double));

		// computation of the X and Prob vectors
		viterbi_log(mat_class, Test_Vect, X, Prob);

		// to avoid to stock all the results, save only the best
		if (Prob[T] > max_prob){
			memcpy(Align, X, T*sizeof(int));
			memcpy(Prob_vect, Prob, T*sizeof(double));
			winner = nC;
			max_prob = Prob[T];
		}

		// free the allocated memory
		free(X);
		free(Prob);
	}

	return winner;
}