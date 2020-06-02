#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "TestMatrix.h"


int test_matrix(void);

int test_matrix(void)
{
	double arr[9] = { 1,2,3,4,5,6,7,8,9 };

	printf("create 3X3 matrix!\n");
	tMatrix mat = CreateMatrix(arr, 3, 3);
	PrintMatrix(&mat);

}