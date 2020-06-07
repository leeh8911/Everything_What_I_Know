#ifndef __EWIK_MATRIX_H__
#define __EWIK_MATRIX_H__

#define MATRIX_MAX_SIZE_ROW (10)
#define MATRIX_MAX_SIZE_COL (10)

typedef struct matrix matrix_t;
typedef struct matrix
{
	// this ptr
	matrix_t* this;

	// member variables
	int size_row;
	int size_col;
	double value[MATRIX_MAX_SIZE_ROW][MATRIX_MAX_SIZE_COL];
	
	void (*Print)(matrix_t* this);
	int (*GetSizeRow)(matrix_t* this);
	int (*GetSizeCol)(matrix_t* this);

	int (*GetValue)(matrix_t* this, int row, int col);
	int (*SetValue)(matrix_t* this, int row, int col, double value);

}matrix_t;

matrix_t* CreateMatrix(int size_row, int size_col);
void DeleteMatrix(matrix_t* src);
#endif