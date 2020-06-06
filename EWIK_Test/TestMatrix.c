#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "TestMatrix.h"


int test_matrix(void);

int test_matrix(void)
{
	return 1;
}

int create_test(void)
{
	matrix_t* A = CreateMatrix(3, 3);
	double a[3][3] = { {1,2,3},{4,5,6},{4,3,2} };
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			A->SetValue(A, i, j, a[i][j]);
		}
	}

	A->Print(A);

	return 1;
}