#ifndef STRUCTMAT_H_INCLUDED
#define STRUCTMAT_H_INCLUDED

/*
#define N 6
#define D 5
#define K 3
#define NClasses 3
*/

#define N 5
#define D 3
#define K 7
#define NClasses 1

struct Matrix
{
	double A[N][N];		  // Transition Matrix
	double MU[D][N][K];   // Emission Matrix (MU)
	double SIGMA[D][N][K];// Emission Matrix (SIGMA)
	double PComp[N][K];   // Emission Matrix (PComp)
};

#endif