#include <stdio.h>
#include <stdlib.h>

#include "EWIK_Matrix.h"

void CreateCell(pCell cell, int row, int col, double value)
{
	cell = (pCell)malloc(sizeof(Cell));
	cell->col = col;
	cell->row = row;
	cell->value = value;
	cell->next_row = NULL;
	cell->next_col = NULL;
}
void CreateMatrix(void)
{
	int number_of_row = 2, number_of_col = 3;
	double mat_in[6] = { 1, 2, 3, 4, 5, 6 };
	Matrix mat;

	mat.number_of_row = number_of_row;
	mat.number_of_col = number_of_col;
	mat.headCell = NULL;

	pCell temp = mat.headCell;
	for (int row = 0; row < number_of_row; row++)
	{
		for (int col = 0; col < number_of_col; col)
		{
			int input_index = col + number_of_col * row;
			if (mat_in[input_index] != 0)
			{
				if (temp == NULL)
				{
					temp = (pCell)malloc(sizeof(Cell));
					temp->col = col;
					temp->row = row;
					temp->value = mat_in[input_index];
				}
			}
		}
	}
}