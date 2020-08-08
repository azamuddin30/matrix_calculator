
// matrix_calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<iomanip>
#include<fstream>


using namespace std;
const int NUMSQ=5;
//matrix power
void matCopy(int mat1[NUMSQ][NUMSQ], int mat2[NUMSQ][NUMSQ]);
void matPower(int ans[NUMSQ][NUMSQ]);
void createIdenMat(int arr[NUMSQ][NUMSQ], int row, int col);
//mattrix addition and subtraction
void matAdd(int a[][NUMSQ], int b[][NUMSQ], int sum[][NUMSQ]);
void matSubtraction(int a[][NUMSQ], int b[][NUMSQ], int sub[][NUMSQ]);

//matrix transpose
void transposeMat(int arr[NUMSQ][NUMSQ], int arr2[NUMSQ][NUMSQ]);
//matrix determinant
void detDriverFunc(int arr[NUMSQ][NUMSQ]);
//matrix multiplication
void multMatrix(int a[NUMSQ][NUMSQ], int b[NUMSQ][NUMSQ], int product[NUMSQ][NUMSQ]);
void insertData(int [NUMSQ][NUMSQ] ,int,int );
void initialize(int ans[NUMSQ][NUMSQ], int row, int col);
void matMultiCore(int a[NUMSQ][NUMSQ], int b[NUMSQ][NUMSQ], int product[NUMSQ][NUMSQ], int row1, int col2, int common);
//void print2DArr(int [NUMSQ][NUMSQ], int , int );
//InverseMatrix
void getCfactor(int M[NUMSQ][NUMSQ], int t[NUMSQ][NUMSQ], int p, int q, int n);
void ADJ(int M[NUMSQ][NUMSQ], int adj[NUMSQ][NUMSQ], int num);
bool INV(int M[NUMSQ][NUMSQ], float inv[NUMSQ][NUMSQ], int n);
int DET(int M[NUMSQ][NUMSQ], int n);
void invMatDriver(int arr[NUMSQ][NUMSQ], float inv[NUMSQ][NUMSQ]);
template<class T>
void print(T G[NUMSQ][NUMSQ],int row,int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << G[i][j] << " "; 
        cout << endl;

    }
}


int main() 
{
    int product[NUMSQ][NUMSQ],arr1[NUMSQ][NUMSQ],arr2[NUMSQ][NUMSQ];
    float inverseMat[NUMSQ][NUMSQ];
    int userChoice;

    cout << "List of Matrix Operation :\n"
        << "1.Matrix Multiplication\n"
        << "2.Matrix Inverse\n"
        << "3.Matrix Transpose\n"
        << "4.Matrix Addition\n"
        << "5.Matrix Subtraction\n"
        << "6.Matrix Power\n"
        << "7.Matrix Determinant\n"
        <<"Enter your option (1-7) :";

    cin >> userChoice;

    switch (userChoice)
    {
        case 1:
            multMatrix(arr1, arr2, product);
            break;
        case 2:
            invMatDriver(arr1,inverseMat);
            break;
        case 3:
            transposeMat(arr1,  arr2);
            break;
        case 4:
            matAdd(arr1, arr2, product);
            break;
        case 5:
            matSubtraction(arr1, arr2, product);
            break;
        case 6:
            matPower(product);
            break;
        case 7:
            detDriverFunc(arr1);
            break;
        default:
            cout << "\nNot a valid option\n";
            
            
    }

    
   
    return 0;
}
// multiplication functions driver
void multMatrix(int a[NUMSQ][NUMSQ],int b[NUMSQ][NUMSQ],int product[NUMSQ][NUMSQ])
{   
    int i, j, k,row1,row2,col1,col2;
    

    cout << "Enter the row and column for matrix 1: ";
    cin >> row1 >> col1;


    cout << "Enter the row and column for matrix 2: ";
    cin >> row2 >> col2;

    if (row1 > NUMSQ || col1 > NUMSQ || row2 > NUMSQ || col2 > NUMSQ)
    {
        cout << "\nPlease change the NUMSQ constant in cpp to increase Maximum Row and Column\n";
        return;
    }else if (row1 <= 0 || col1 <= 0 || col2 <= 0 || row2 <= 0)
    {
        cout << "\nRow and Column  equal 0 or less\n";
        return;
    }
    else if (col1 != row2)
    {
        cout << "Column of first matrix should be equal to row of second matrix\n";
    }
    else
    {
        initialize(a, NUMSQ, NUMSQ);
        initialize(b, NUMSQ, NUMSQ);
        cout << "Enter the Elements for matrix 1: \n";
        insertData( a,  row1,  col1);
        cout << "Enter the Elements for matrix 2: \n";
        insertData( b,  row2,  col2);
       
        initialize(product, NUMSQ, NUMSQ);
        matMultiCore(a, b, product, row1, col2, col1);
        //for (i = 0; i < row1; ++i)
            //for (j = 0; j < col2; ++j)
              //  for (k = 0; k < col1; ++k)
               // {
               //     product[i][j] += a[i][k] * b[k][j];
               // }
        cout << "The Product of multiplication is: \n";
        print( product,  row1,  col2);
       
    }

    

    return;
}

void insertData(int arr[NUMSQ][NUMSQ],int row, int col)
{   

   
    cout << "The elements of ["<<row <<"] ["<<col<<"] matrix :" << endl;
   
    for (int i = 0; i < row; i++) 
    {
        
        for (int j = 0; j < col; j++)
        {
           
            cin >> arr[i][j];
        }
        
    }


    return ;
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

void matMultiCore(int a[NUMSQ][NUMSQ], int b[NUMSQ][NUMSQ], int product[NUMSQ][NUMSQ], int row1, int col2, int common)
{
    int i, j, k;
    for (i = 0; i < row1; ++i)
        for (j = 0; j < col2; ++j)
            for (k = 0; k < common; ++k)
            {
                product[i][j] += a[i][k] * b[k][j];
            }

    return;
}


// Inverse Matrix Function driver
void invMatDriver(int arr[NUMSQ][NUMSQ], float inv[NUMSQ][NUMSQ])
{
    int row, col;
    cout << "Enter the number of row and column: ";
    cin >> row >> col;

    while (row != col)
    {
        cout << "The inverse Operation is only for square Matrix row=col\n";
        cout << "Enter the number of row and column :";
        cin >> row >> col;
    }

    if (row > NUMSQ || col > NUMSQ)
    {
        cout << "\nPlease change the NUMSQ constant in cpp to increase Maximum Row and Column\n";
        return;
    }else if (row <= 0 || col <= 0 )
    {
        cout << "Row and Column cannot be equal 0 and less\n";
        return;
    }

   

    // row = num;
    initialize(arr, NUMSQ, NUMSQ);
    insertData(arr, row, row);
    cout << "Input matrix is :\n";
    print(arr, row, row);
    cout << "\nThe Inverse is :\n";
    if (INV(arr, inv, row))
        print(inv, row, row);


    return;
}

void getCfactor(int M[NUMSQ][NUMSQ], int t[NUMSQ][NUMSQ], int lockedRow, int lockedCol, int sqSide)
{
    int i = 0, j = 0;
    for (int r = 0; r < sqSide; r++)
    {
        for (int c = 0; c < sqSide; c++) //Copy only those elements which are not in given row r and column c: {
        {
            if (r != lockedRow && c != lockedCol)
            {
                t[i][j++] = M[r][c]; 
                if (j == sqSide - 1)//If row is filled  
                {
                    j = 0; //and reset column index
                    i++;//increase r index
                }
            }

        }

    }
}

int DET(int M[NUMSQ][NUMSQ], int n) //to find determinant 
{
    int D = 0;
    if (n == 1)
        return M[0][0];

    int t[NUMSQ][NUMSQ]; //contain  cofactors
    int s = 1; //store sign alternating int
   //To Iterate each element of first row
    for (int f = 0; f < n; f++)
    {
        //For Getting submatrix of M[0][f]
        getCfactor(M, t, 0, f, n);
        D += s * M[0][f] * DET(t, n - 1);
        s = -s;

    }
    return D;
}

void ADJ(int M[NUMSQ][NUMSQ], int adj[NUMSQ][NUMSQ],int num)
{
    if (num == 1)
    {
        adj[0][0] = 1;
        return;
    }

    int s = 1, t[NUMSQ][NUMSQ];

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            //To get cofactor of M[i][j]
            getCfactor(M, t, i, j, num);
            s = ((i + j) % 2 == 0) ? 1 : -1; //sign of adj[j][i] positive if sum of row and column indexes is even.
            adj[j][i] = (s) * (DET(t, num - 1)); //Interchange rows and columns to get the transpose of the cofactor matrix
        }
    }
}

bool INV(int M[NUMSQ][NUMSQ], float inv[NUMSQ][NUMSQ], int n) 
{
    int det = DET(M, n);
    if (det == 0)
    {
        cout << "\nDeterminant is Zero,Hence not inversible\n";
        return false;
    }
    int adj[NUMSQ][NUMSQ]; 

    ADJ(M, adj,n);// need to adjust this function or just paste it here, col and row problem at declaration

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            inv[i][j] = adj[i][j] / float(det);
    return true;
}


//Matrix determinant driver

void detDriverFunc(int arr[NUMSQ][NUMSQ])
{
    int row, col;
    cout << "Enter the number of row and column: ";
    cin >> row >> col;
    

    while (row != col)
    {
        cout << "The inverse Operation is only for square Matrix row=col\n";
        cout << "Enter the number of row and column :";
        cin >> row >> col;
    }

    if (row > NUMSQ || col > NUMSQ)
    {
        cout << "\nPlease change the NUMSQ constant in cpp to increase Maximum Row and Column\n";
        return;
    }else if (row <= 0 || col <= 0 )
    {
        cout << "\nPlease change the NUMSQ constant in cpp to increase Maximum Row and Column\n"
             << "Row and Column exceed the allocated size or equal 0 and less\n";
        return;
    }

    initialize(arr, NUMSQ, NUMSQ);
    insertData(arr, row, row);
    cout << "Input matrix is :\n";
    print(arr, row, row);
    
    // only square matrix , so row=col
    cout<<"The Determinant of ["<<row<<"]["<<col<<"] matrix is "<< DET(arr, row)<<"\n";
    


    return;
}

//Matrix transpose driver
void transposeMat(int arr[NUMSQ][NUMSQ], int arr2[NUMSQ][NUMSQ])
{   

    initialize(arr, NUMSQ, NUMSQ);
    initialize(arr2, NUMSQ, NUMSQ);

    int row, col;
    cout << "Enter the number of row and column: ";
    cin >> row >> col;

    if (row > NUMSQ || col > NUMSQ)
    {
        cout << "\nPlease change the NUMSQ constant in cpp to increase Maximum Row and Column\n";
        return;
    }else if (row <= 0 || col <= 0 )
    {
        cout << "\nPlease change the NUMSQ constant in cpp to increase Maximum Row and Column\n"
            << "Row and Column exceed the allocated size or equal 0 and less\n";
        return;
    }

    


    insertData(arr, row, col);
   
    cout << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr2[j][i] = arr[i][j];
            //cout << endl << arr2[j][i] << "<----" << arr[i][j] << endl;
        }
    }
        
    
    cout << "The transpose matrix is:" << endl;
    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++j)
            cout << arr2[i][j] << " ";
        cout << endl;
    }
        
    


    return;
}

//Matrix Addition & subtraction
void matAdd(int a[][NUMSQ], int b[][NUMSQ], int sum[][NUMSQ]) 
{   
    initialize(a, NUMSQ, NUMSQ);
    initialize(b, NUMSQ, NUMSQ);
    initialize(sum, NUMSQ, NUMSQ);

    int i, j, row1, row2, col1, col2;


    cout << "Enter the row and column for matrix 1: ";
    cin >> row1 >> col1;


    cout << "Enter the row and column for matrix 2: ";
    cin >> row2 >> col2;


    if (col1 != col2 && row1!=row2)
    {
        cout << "Column and row of first matrix should be equal to column and row of second matrix";
        return;
    }
    else if (row1 > NUMSQ || col1 > NUMSQ||row2 > NUMSQ || col2 > NUMSQ)
    {
        cout << "\nPlease change the NUMSQ constant in cpp to increase Maximum Row and Column\n";
        return;

    }
    else if (row1 <= 0 || col1 <= 0 || col2 <= 0 || row2 <= 0)
    {
        cout << "\nPlease change the NUMSQ constant in cpp to increase Maximum Row and Column\n"
            << "Row and Column exceed the allocated size or equal 0 and less\n";
        return;
    }
    else
    {
        insertData(a, row1, col1);
        insertData(b, row2, col2);
        cout << endl;
        for (i = 0; i < row1; ++i)
            for (j = 0; j < col1; ++j)
                sum[i][j] = a[i][j] + b[i][j];

        cout << "Sum of the two matrices is:" << endl;
        for (i = 0; i < row1; ++i) {
            for (j = 0; j < col1; ++j)
                cout << sum[i][j] << " ";
            cout << endl;
        }
    }

   
    return;
}

void matSubtraction(int a[][NUMSQ], int b[][NUMSQ], int sub[][NUMSQ]) 
{

    initialize(a, NUMSQ, NUMSQ);
    initialize(b, NUMSQ, NUMSQ);
    initialize(sub, NUMSQ, NUMSQ);

    int i, j, row1, row2, col1, col2;


    cout << "Enter the row and column for matrix 1: ";
    cin >> row1 >> col1;


    cout << "Enter the row and column for matrix 2: ";
    cin >> row2 >> col2;


    if (col1 != col2 && row1 != row2)
    {
        cout << "Column and row of first matrix should be equal to column and row of second matrix";
        return;
    }
    else if (row1 > NUMSQ || col1 > NUMSQ || row2 > NUMSQ || col2 > NUMSQ)
    {
        cout << "\nPlease change the NUMSQ constant in cpp to increase Maximum Row and Column\n";
        return;

    }else if (row1 <= 0 || col1 <= 0 || col2 <= 0 || row2 <= 0)
    {
        cout << "\nPlease change the NUMSQ constant in cpp to increase Maximum Row and Column\n"
            << "Row and Column exceed the allocated size or equal 0 and less\n";
        return;
    }
    else
    {
        insertData(a, row1, col1);
        insertData(b, row2, col2);
        cout << endl;
        for (i = 0; i < row1; ++i)
            for (j = 0; j < col1; ++j)
                sub[i][j] = a[i][j] - b[i][j];

        cout << "Minus of the two matrices is:" << endl;
        for (i = 0; i < row1; ++i) 
        {
            for (j = 0; j < col1; ++j)
                cout << sub[i][j] << " ";
            cout << endl;
        }
    }


    return;
}

//Matrix Power
void matPower(int ans[NUMSQ][NUMSQ])
{   
    int original[NUMSQ][NUMSQ];
    int container[NUMSQ][NUMSQ];

    initialize(ans, NUMSQ, NUMSQ);
    initialize(original, NUMSQ, NUMSQ);
    initialize(container, NUMSQ, NUMSQ);


    int row, col;
    cout << "Enter the number of row and column: ";
    cin >> row >> col;
    while (row != col)
    {
        cout << "The inverse Operation is only for square Matrix row=col\n";
        cout << "Enter the number of row and column :";
        cin >> row >> col;
    }

    if (row > NUMSQ || col > NUMSQ || col<=0 || row <=0)
    {
        cout << "\nPlease change the NUMSQ constant in cpp to increase Maximum Row and Column\n"
             <<"Row and Column exceed the allocated size or equal 0 and less\n";
        return;
    }
    
    cout << "Enter the matrix \n";
    insertData(original, row, col);

    cout << "Enter the power of the matrix :";
    int userInput,numMultiplier;
    cin >> userInput;

    
    if (userInput==0)
    {
        cout << "The Answer is identity Matrix\n";
        createIdenMat(container,row,col);
        print(container, row, col);
    }
    else if (userInput==1)
    {
        cout << "The answer is: \n";
        print(original, row, col);
    }
    else
    {
        numMultiplier = userInput - 2;
        matMultiCore(original, original, ans,row,col,col);
        if (numMultiplier ==0)
        {   
            cout << "The answer is: \n";
            print(ans, row, col);
        }else
        {   
            cout << "The Answer is :\n";
            for (int i = 0; i < numMultiplier; i++)
            {
                matMultiCore(ans, original, container,row,col,col);
                matCopy(ans, container);
                initialize(container,NUMSQ,NUMSQ);
            }
            print(ans, row, col);
        
        }
           


    }

   


    return;
}

void matCopy(int mat1[NUMSQ][NUMSQ], int mat2[NUMSQ][NUMSQ])
{

    for (int i = 0; i < NUMSQ; i++)
    {

        for (int j = 0; j < NUMSQ; j++)
        {

            mat1[i][j] = mat2[i][j];
        }

    }
    cout << "\nThe matrix on right is copied to the left\n";


    return;
}

void createIdenMat(int arr[NUMSQ][NUMSQ], int row, int col)
{

    int i, j;
    for (i = 0; i < row; ++i)
    {
        for (j = 0; j < col; ++j)
        {
            if (i == j)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = 0;

            }

        }

    }
        
    


    return;
}
