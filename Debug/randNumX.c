#include <stdio.h>
#include <stdlib.h>
#include "randNumX.h"

#define RAND_MAX 32767

double randNumX(double max) {
	return ((double)rand() / (double)(RAND_MAX)) * max;
}