#include <stdio.h>
#include <stdlib.h>
#include "randNumX.h"

float randNumX(float max) {
return ((float)rand() / (float)(RAND_MAX)) * max;
}
