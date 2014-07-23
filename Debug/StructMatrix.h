#ifndef STRUCTMAT_H_INCLUDED
#define STRUCTMAT_H_INCLUDED

#define T 40
#define N 5
#define D 30
#define K 10
#define NClasses 10

struct Matrix
{
	double A[N][N];		  // Transition Matrix
	double MU[D][N][K];   // Emission Matrix (MU)
	double SIGMA[D][N][K];// Emission Matrix (SIGMA)
	double PComp[N][K];   // Emission Matrix (PComp)

};

#endif