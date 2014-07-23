/* hello.c */
#include <stdio.h>
#include "StructMatrix.h"
#include "LearnMatrix.h"
#include "randNumX.h"

#define T 40

int main() {

	// create a random struct matrix
	// TODO: charge the correct struct matrix
	struct Matrix * foo_mat = LearnMatrix();

	// generate a sample long dimT
	double Test_Vect[D][T];
	for (int d = 0; d < D; d++)
		for (int t = 0; t < T;  t++)
			Test_Vect[d][t] = randNumX(3.0);

	// initialization of the test parameters
	int winner = -1;
	int *Align = calloc(T, sizeof(int));
	double *Prob_vect = calloc(T, sizeof(double));

	// test the sample using the trained Matrix
	winner = TestMatrix(foo_mat, Test_Vect, Align, Prob_vect);

	// print the resuts
	for (int t = 0; t < T; t++)
		printf("%d ", Align[t]);
	printf("\n");
	for (int t = 0; t < T; t++)
		printf("%f ", Prob_vect[t]);
	printf("\n\n");
	printf("And the winner is...\n");
	printf("%d",winner);
	printf("\n\n");

	// wait for the user input
	printf("Insert an integer!\n");
	int numITM;
	scanf("%d", &numITM);

	// free the allocated memory
	free(Align);
	free(Prob_vect);

	return 0;
}