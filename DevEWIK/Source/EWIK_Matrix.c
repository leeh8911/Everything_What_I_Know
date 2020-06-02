#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "EWIK_Matrix.h"

// Declare global extern function
tMatrix CreateMatrix(double* arr, int size_row, int size_col);
void DeleteMatrix(tMatrix*);
void PrintMatrix(tMatrix*);

double GetValueFromMatrix(tMatrix* src, int row, int col);
void SetValueInMatrix(tMatrix* des, int row, int col, double value);

tMatrix AddMatrix(tMatrix* A, tMatrix* B);
tMatrix MulMatrix(tMatrix* A, tMatrix* B);
double DeterminantOfMatrix(tMatrix* A);
tMatrix InverseMatrix(tMatrix* A);
tMatrix TransposeMatrix(tMatrix* A);

// Declare local static function
static tNode* CreateNode(double value, int row, int col, tNode* next);


//

// Matrix_{ij} = arr[i*size_col+j]
tMatrix CreateMatrix(double* arr, int size_row, int size_col)
{
	int i = 0, total_size = size_row * size_col;
	int row, col;
	tMatrix result;
	tNode *temp = NULL;
	result.head = NULL;
	result.num_of_col = size_col;
	result.num_of_row = size_row;
	result.size = 0;

	for (i = 0; i < total_size; i++)
	{
		row = i / size_col;
		col = i % size_col;
		if (arr[i] == 0)
		{
			continue;
		}
		if (result.head == NULL)
		{
			result.head = CreateNode(arr[i], row, col, NULL);
			result.size++;

			temp = result.head;
		}
		else
		{
			temp->next = CreateNode(arr[i], row, col, NULL);
			result.size++;

			temp = temp->next;
		}
	}


	return result;
}


tNode* CreateNode(double value, int row, int col, tNode* next)
{
	tNode* temp = (tNode*)malloc(sizeof(tNode));
	memset(temp, 0, sizeof(tNode));

	temp->row = row;
	temp->col = col;
	temp->value = value;
	temp->next = next;

	return temp;
}


void PrintMatrix(tMatrix* matrix)
{
	int size_row = matrix->num_of_row, size_col = matrix->num_of_col;
	int size = matrix->size;
	int i = 0, j = 0, row = 0, col = 0;
	tNode* temp = matrix->head;
	double** arr = (double**)malloc(sizeof(double*) * size_row);
	for (i = 0; i < size_row; i++)
	{
		arr[i] = (double*)malloc(sizeof(double) * size_col);
		memset(arr[i], 0, sizeof(double) * size_col);
	}

	for (i = 0; i < size; i++)
	{
		row = i / size_col;
		col = i % size_col;

		arr[row][col] = GetValueFromMatrix(matrix, row, col);
	}

	
	for (i = 0; i < size_row; i++)
	{
		printf("| ");
		for (j = 0; j < size_col; j++)
		{
			printf("%6.2f ", arr[i][j]);
		}
		printf("| \n");
	}
}


double GetValueFromMatrix(tMatrix* src, int row, int col)
{
	double result = 0;
	int flag_get = 0;
	tNode* temp = src->head;
	while (temp != NULL && flag_get == 0)
	{
		if (temp->row == row && temp->col == col)
		{
			result = temp->value;
			flag_get = 1;
		}
		else
		{
			temp = temp->next;
		}
	}

	return result;
}


//TODO : List!

void SetValueInMatrix(tMatrix* des, int row, int col, double value)
{
	tNode* curr = des->head;
	tNode* temp = NULL;

	int set_flag = 0;
	while (curr != NULL && set_flag == 0)
	{
		if (curr->row == row && curr->col == col)
		{
			curr->value = value;
			set_flag = 1;
		}
		else
		{
			curr = curr->next;
		}
	}

	if(set_flag == 0)
	{
		curr->next = (tNode*)malloc(sizeof(tNode));
	}
}

tMatrix AddMatrix(tMatrix* A, tMatrix* B) {}
tMatrix MulMatrix(tMatrix* A, tMatrix* B) {}
double DeterminantOfMatrix(tMatrix* A) {}
tMatrix InverseMatrix(tMatrix* A){}
tMatrix TransposeMatrix(tMatrix* A){}
