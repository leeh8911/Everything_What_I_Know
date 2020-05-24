#include <stdio.h>
#include <stdlib.h>

#include "EWIK_Matrix.h"

SparseMatrix CreateMatrix(void)
{
	int number_of_row = 2, number_of_col = 3;
	double mat_in[6] = { 1, 2, 3, 4, 5, 6 };

	SparseMatrix mat;
	mat.num_of_row = number_of_row;
	mat.num_of_col = number_of_col;
	mat.head = NULL;

	pNode temp = mat.head;
	if (number_of_row != 0 && number_of_col != 0)
	{

	}
	else
	{

	}
}