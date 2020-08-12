#pragma once
extern const int NUMSQ;
//FILE operation
void printFile(userHistory* ptrK, int index);
//update struct fn
void updateStruct(userHistory* ptr, int current, int search);
void resetStruct(userHistory*& ptrK, int& index, int histNum2);
// struct operation
void fillStruct(int arr[NUMSQ][NUMSQ], int arr2[NUMSQ][NUMSQ], float arrO[NUMSQ][NUMSQ], string id, userHistory* ptr, int row, int col);
void initialiseStructArr(userHistory* ptr);
void convertToFloatArray(int arr[NUMSQ][NUMSQ], float arrF[NUMSQ][NUMSQ]);
void printStruct(userHistory* ptr, int index);
void initialize(float ans[NUMSQ][NUMSQ], int row, int col);//overload fn initialize
//matrix power
void matCopy(int mat1[NUMSQ][NUMSQ], int mat2[NUMSQ][NUMSQ]);
void matPower(int ans[NUMSQ][NUMSQ], userHistory* ptr);
void createIdenMat(int arr[NUMSQ][NUMSQ], int row, int col);
//mattrix addition and subtraction
void matAdd(int a[][NUMSQ], int b[][NUMSQ], int sum[][NUMSQ], userHistory* ptr);
void matSubtraction(int a[][NUMSQ], int b[][NUMSQ], int sub[][NUMSQ], userHistory* ptr);

//matrix transpose
void transposeMat(int arr[NUMSQ][NUMSQ], int arr2[NUMSQ][NUMSQ], userHistory* ptr);
//matrix determinant
void detDriverFunc(int arr[NUMSQ][NUMSQ], userHistory* ptr);
//matrix multiplication
void multMatrix(int a[NUMSQ][NUMSQ], int b[NUMSQ][NUMSQ], int product[NUMSQ][NUMSQ], userHistory* ptr);
void insertData(int[NUMSQ][NUMSQ], int, int);
void initialize(int ans[NUMSQ][NUMSQ], int row, int col);
void matMultiCore(int a[NUMSQ][NUMSQ], int b[NUMSQ][NUMSQ], int product[NUMSQ][NUMSQ], int row1, int col2, int common);
//void print2DArr(int [NUMSQ][NUMSQ], int , int );
//InverseMatrix
void getSubMat(int M[NUMSQ][NUMSQ], int t[NUMSQ][NUMSQ], int p, int q, int n);
void MatAdj(int M[NUMSQ][NUMSQ], int adj[NUMSQ][NUMSQ], int num);
void InvFunc(int M[NUMSQ][NUMSQ], float inv[NUMSQ][NUMSQ], int n, bool& check);
int findDet(int M[NUMSQ][NUMSQ], int n);
void invMatDriver(int arr[NUMSQ][NUMSQ], float inv[NUMSQ][NUMSQ], userHistory* ptr);