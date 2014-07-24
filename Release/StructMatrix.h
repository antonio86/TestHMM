#ifndef STRUCTMAT_H_INCLUDED
#define STRUCTMAT_H_INCLUDED

#define T 40
#define N 5
#define D 3
#define K 7
#define NClasses 1

struct Matrix
{
float A[N][N];	// Transition Matrix
float MU[D][N][K]; // Emission Matrix (MU)
float SIGMA[D][N][K];// Emission Matrix (SIGMA)
float PComp[N][K]; // Emission Matrix (PComp)

};

#endif
