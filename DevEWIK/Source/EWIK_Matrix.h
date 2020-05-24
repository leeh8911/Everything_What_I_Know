#pragma once

typedef struct Node* pNode;
typedef struct tNode
{
	int row, col;
	double value;
	pNode next_row, next_col;
}Node;

typedef struct tSparseMatrix
{
	int num_of_row, num_of_col;
	pNode head;
}SparseMatrix;


extern SparseMatrix CreateMatrix(void);