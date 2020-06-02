#ifndef __EWIK_MATRIX_H__
#define __EWIK_MATRIX_H__

struct Node
{
	int row;
	int col;
	double value;
	struct Node *next;
};

struct Matrix
{
	int size;
	int num_of_row, num_of_col;
	struct Node* head;
};

typedef struct Matrix tMatrix;
typedef struct Node tNode;


extern tMatrix CreateMatrix(double* arr, int size_row, int size_col);
extern void DeleteMatrix(tMatrix*);
extern void PrintMatrix(tMatrix*);

extern double GetValueFromMatrix(tMatrix* src, int row, int col);
extern void SetValueInMatrix(tMatrix* des, int row, int col, double value);

extern tMatrix AddMatrix(tMatrix* A, tMatrix* B);
extern tMatrix MulMatrix(tMatrix* A, tMatrix* B);
extern double DeterminantOfMatrix(tMatrix* A);
extern tMatrix InverseMatrix(tMatrix* A);
extern tMatrix TransposeMatrix(tMatrix* A);




#endif