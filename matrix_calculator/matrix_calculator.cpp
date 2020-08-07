
// matrix_calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
using namespace std;
const int NUMSQ=5;

void multMatrix(int a[NUMSQ][NUMSQ], int b[NUMSQ][NUMSQ], int product[NUMSQ][NUMSQ]);
void insertData(int [NUMSQ][NUMSQ] ,int,int );
void initialize(int ans[NUMSQ][NUMSQ], int row, int col);
void print2DArr(int [NUMSQ][NUMSQ], int , int );

int main() {
    int product[NUMSQ][NUMSQ],arr1[NUMSQ][NUMSQ],arr2[NUMSQ][NUMSQ];
    double inverseMat[NUMSQ][NUMSQ];
    int userChoice;

    cout << "List of Matrix Operation :\n"
        << "1.Matrix Multiplication\n"
        << "2.Matrix Inverse\n"
        << "3.Matrix Transpose\n"
        << "4.Matrix Addition\n"
        << "5.Matrix Subtraction\n"
        << "6.Matrix Power\n"
        << "7.Matrix Determinant\n"
        <<"Enter your option :";

    cin >> userChoice;

    switch (userChoice)
    {
        case 1:
            multMatrix(arr1, arr2, product);
            break;
        case 2:
            multMatrix(arr1, arr2, product);
            break;
        case 3:
            multMatrix(arr1, arr2, product);
            break;
        case 4:
            multMatrix(arr1, arr2, product);
            break;
        case 5:
            multMatrix(arr1, arr2, product);
            break;
        case 6:
            multMatrix(arr1, arr2, product);
            break;
        case 7:
            multMatrix(arr1, arr2, product);
            break;
        default:
            cout << "\nNot a valid option\n";
            break;
            
    }

    
   
    return 0;
}

void multMatrix(int a[NUMSQ][NUMSQ],int b[NUMSQ][NUMSQ],int product[NUMSQ][NUMSQ])
{   
    int i, j, k,row1,row2,col1,col2;
    

    cout << "Enter the row and column for matrix 1: ";
    cin >> row1 >> col1;


    cout << "Enter the row and column for matrix 2: ";
    cin >> row2 >> col2;


    if (col1 != row2)
    {
        cout << "Column of first matrix should be equal to row of second matrix";
    }
    else
    {
        initialize(a, NUMSQ, NUMSQ);
        initialize(b, NUMSQ, NUMSQ);

        insertData( a,  row1,  col1);
        insertData( b,  row2,  col2);
       
        initialize(product, NUMSQ, NUMSQ);

        for (i = 0; i < row1; ++i)
            for (j = 0; j < col2; ++j)
                for (k = 0; k < col1; ++k)
                {
                    product[i][j] += a[i][k] * b[k][j];
                }

        print2DArr( product,  row1,  col2);
       
    }

    

    return;
}

void insertData(int arr[NUMSQ][NUMSQ],int row, int col)
{   

   
    cout << "The elements of ["<<row <<"] ["<<col<<"] matrix :" << endl;
   
    for (int i = 0; i < row; i++) 
    {
        
        for (int j = 0; j < col; ++j)
        {
           
            cin >> arr[i][j];
        }
        
    }


    return ;
}

void print2DArr(int ans[NUMSQ][NUMSQ],int row, int col)
{
    cout << "The answer matrix is:" << endl;
    for (int i = 0; i < row; ++i) 
    {
        for (int j = 0; j < col; ++j)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    cout << endl;


    return;
}

void initialize(int ans[NUMSQ][NUMSQ], int row, int col)
{
    cout << "Initialize the matrix " << endl;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            ans[i][j] = 0;
        }
   

    return;
}