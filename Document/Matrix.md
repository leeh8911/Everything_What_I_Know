# Matrix.c

* [20/5/24] : 시작

# Lesson


# Reference




# List of functions

```c
Matrix* CreateMatrixByArr(double *arr, int size_row, int size_col);
```

2차원 배열을 1차원 배열로 변환한 것을 입력으로 하여 Matrix 구조체를 생성해줌, 입력 배열이 NULL이면, 이는 matlab에서의 zeros와 동일

```c
Matrix* CreateMatrixByMat(Matrix* src);
```

이전에 존재한 Matrix와 동일한 Matrix를 생성함

```c
void DeleteMatrix(Matrix* src);
```

입력된 Matrix 포인터에 할당된 모든 메모리를 해제함.