#pragma once


typedef struct tCell* pCell;
typedef struct tCell
{
	int row;
	int col;
	double value;
	pCell next_row;
	pCell next_col;
}Cell;

typedef struct tMatrix
{
	int number_of_row;
	int number_of_col;
	pCell headCell;
}Matrix;