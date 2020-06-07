#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "EWIK_Matrix.h"

matrix_t* CreateMatrix(int size_row, int size_col);
void DeleteMatrix(matrix_t* src);

void Print_(matrix_t* this);
int GetSizeRow_(matrix_t* this);
int GetSizeCol_(matrix_t* this);

int GetValue_(matrix_t* this, int row, int col);
void SetValue_(matrix_t* this, int row, int col, double value);




matrix_t* CreateMatrix(int size_row, int size_col)
{
	matrix_t* result = (matrix_t*)malloc(sizeof(matrix_t));
	memset(result, 0, sizeof(matrix_t));

	result->size_col = size_col;
	result->size_row = size_row;

	//
	result->this = result;

	result->Print = Print_;

	result->GetSizeRow = GetSizeRow_;
	result->GetSizeCol = GetSizeCol_;

	result->GetValue = GetValue_;
	result->SetValue = SetValue_;

	return result;
}

void DeleteMatrix(matrix_t* src)
{
	free(src);
	src = NULL;
}

int GetSizeRow_(matrix_t* this)
{
	return this->size_row;
}
int GetSizeCol_(matrix_t* this)
{
	return this->size_col;
}

int GetValue_(matrix_t* this, int row, int col)
{
	return this->value[row][col];
}
void SetValue_(matrix_t* this, int row, int col, double value)
{
	this->value[row][col] = value;
}
void Print_(matrix_t* this)
{
	int size_row = this->GetSizeRow(this);
	int size_col = this->GetSizeCol(this);
	int i, j;
	double value;
	for (i = 0; i < size_row; ++i)
	{
		printf("|");
		for (j = 0; j < size_col; ++j)
		{
			value = this->GetValue(this, i, j);
			printf("%6.2f ", value);
		}
		printf("|\n");
	}
}