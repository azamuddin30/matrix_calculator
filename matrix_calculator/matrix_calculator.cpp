
// matrix_calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>


using namespace std;
const int NUMSQ=5;
#include"Struct_userHistory.h"
#include"PrototypeFn.h"
template<class T>
void print(T G[NUMSQ][NUMSQ],int row,int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << setw(10) << G[i][j] ;
        cout << endl;

    }
}


int main() 
{
    int product[NUMSQ][NUMSQ],arr1[NUMSQ][NUMSQ],arr2[NUMSQ][NUMSQ];
    float inverseMat[NUMSQ][NUMSQ];
    int userChoice, indexPtr=0, histNum;
    char ch;

    cout << "How many History you need?(multiplication, inverse, transpose, add, minus,power,determinant) : ";
    cin >> histNum;
    if (histNum <= 0)
    {
        cout << "\nThe number of history cannot be 0 or less, Default value of 5 is used..\n";
        histNum = 5;
    }
    userHistory* ptrH = new userHistory[histNum];
    cout<<"\nEnter the Matrix Calculator? Y/N : ";
    cin >> ch;

    while (toupper(ch)=='Y' /*&& indexPtr< histNum*/ )
    {
        cout << "\n\nList of Matrix Operation :\n\n"
            << "1.Matrix Multiplication\n\n"
            << "2.Matrix Inverse\n\n"
            << "3.Matrix Transpose\n\n"
            << "4.Matrix Addition\n\n"
            << "5.Matrix Subtraction\n\n"
            << "6.Matrix Power\n\n"
            << "7.Matrix Determinant\n\n"
            << "8.Read User History\n\n"
            << "9.History: Reset\n\n"
            << "10.History: Print on file\n\n"
            << "11.Exit\n\n"
            << "Enter your option (1-11) :";

        cin >> userChoice;

        switch (userChoice)
        {
        case 1:
            multMatrix(arr1, arr2, product, (ptrH + indexPtr));
            (ptrH + indexPtr)->position = indexPtr;
            indexPtr++;
            break;
        case 2:
            invMatDriver(arr1, inverseMat, (ptrH + indexPtr));
            (ptrH + indexPtr)->position = indexPtr;
            indexPtr++;
            break;
        case 3:
            transposeMat(arr1, arr2, (ptrH + indexPtr));
            (ptrH + indexPtr)->position = indexPtr;
            indexPtr++;
            break;
        case 4:
            matAdd(arr1, arr2, product, (ptrH + indexPtr));
            (ptrH + indexPtr)->position = indexPtr;
            indexPtr++;
            break;
        case 5:
            matSubtraction(arr1, arr2, product, (ptrH + indexPtr));
            (ptrH + indexPtr)->position = indexPtr;
            indexPtr++;
            break;
        case 6:
            matPower(product, (ptrH+indexPtr) );
            (ptrH+indexPtr)->position = indexPtr;
            indexPtr++;
            break;
        case 7:
            detDriverFunc(arr1, (ptrH + indexPtr));
            (ptrH + indexPtr)->position = indexPtr;
            indexPtr++;
            break;
        case 8:
            printStruct(ptrH, indexPtr);
            break;
        case 9:
            resetStruct( ptrH, indexPtr, histNum);
            break;
        case 10:
            printFile(ptrH, indexPtr);
            break;
        case 11:
            delete[] ptrH;
            ptrH = NULL;
            return 1;
        default:
            cout << "\nNot a valid option\n";


        }
        
        if (indexPtr != histNum)
        {
            cout << "\nThe next index for history :" << indexPtr << endl;
        }
       
        
        
        if (indexPtr  == histNum )
        {
            cout << "\nAll History spaces is filled.Exiting...\n";
            cout << "\nDo you want to see and print the history list? Y/N\n";
            char ch2;
            cin >> ch2;
            if (toupper(ch2) == 'Y')
            {
                printStruct(ptrH, indexPtr);

                cout << "\nDo you want to update the history list? Y/N\n";
                cin >> ch2;
                int search;
               
                while (toupper(ch2) == 'Y')
                {
                    cout << "\nEnter the Position You wish to change: ";
                    cin >> search;
                    updateStruct(ptrH, indexPtr, search);

                    cout << "\nDo you want to update the history list? Y/N\n";
                    cin >> ch2;

                }
                cout << "\nDo you want to see the history list? Y/N\n";
                char ch3;
                cin >> ch3;
                if (toupper(ch3) == 'Y')
                {
                    printStruct(ptrH, indexPtr);


                }


                

            }
                

            cout << "\nDo you want to reset the history list? Y/N\n";
            char ch4;
            cin >> ch4;
            if (toupper(ch4) == 'Y')
                resetStruct(ptrH, indexPtr, histNum);
            else
                break;
                
            
        }
        else
        {
            cout << "\n Enter the Matrix again ? Y/N :";
            cin >> ch;
        }

        

    }

    
    
    delete[] ptrH;
    ptrH = NULL;
    return 0;
}
// multiplication functions driver
void multMatrix(int a[NUMSQ][NUMSQ],int b[NUMSQ][NUMSQ],int product[NUMSQ][NUMSQ], userHistory* ptr)
{   
    int i, j, k,row1,row2,col1,col2;
    string id = "Multiplication";
    

    cout << "Enter the row and column for matrix 1 (only m x n multiply by n x m): ";
    cin >> row1 >> col1;


    cout << "Enter the row and column for matrix 2 (only m x n multiply by n x m): ";
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
        return;
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
        
        cout << "The Product of multiplication is: \n";
        print( product,  row1,  col2);
       
    }

    float ans2[NUMSQ][NUMSQ];
    convertToFloatArray(product, ans2);
    fillStruct(a, b, ans2, id, ptr,NUMSQ,NUMSQ);
    
    ptr = NULL;
    return;
}

void insertData(int arr[NUMSQ][NUMSQ],int row, int col)
{   

   
    cout << "The elements of ["<<row <<"] X ["<<col<<"] matrix :" << endl;
   
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
void invMatDriver(int arr[NUMSQ][NUMSQ], float inv[NUMSQ][NUMSQ], userHistory* ptr)
{   
    string id = "Inverse_matrix";
    bool check = false;// check if the determinant >0 , then true and vice versa
    int row, col;
    cout << "Enter the number of row and column (must be square matrix m x m): ";
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
    InvFunc(arr, inv, row, check);
    if (check)
    {
        print(inv, row, row);
        int dummyArray[NUMSQ][NUMSQ];
        initialize(dummyArray, NUMSQ, NUMSQ);
        fillStruct(arr, dummyArray, inv, id, ptr, row, col);


    }
    ptr = NULL;
    return;
}

void getSubMat(int M[NUMSQ][NUMSQ], int t[NUMSQ][NUMSQ], int lockedRow, int lockedCol, int sqSide)
{
    int i = 0, j = 0;
    for (int r = 0; r < sqSide; r++)
    {
        for (int c = 0; c < sqSide; c++) //Copy only those elements which are not in given row r and column c: {
        {
            if (r != lockedRow && c != lockedCol)
            {
                t[i][j++] = M[r][c]; 
                if (j == sqSide - 1)//If row is filled , the row of submatrix always -1 than main matrix
                {
                    j = 0; //and reset column index
                    i++;//increase r index
                }
            }

        }

    }
}

int findDet(int M[NUMSQ][NUMSQ], int n) //to find determinant 
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
        getSubMat(M, t, 0, f, n);
        D += s * M[0][f] * findDet(t, n - 1);
        s = -s;

    }
    return D;
}

void MatAdj(int M[NUMSQ][NUMSQ], int adj[NUMSQ][NUMSQ],int num)
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
            getSubMat(M, t, i, j, num);
            s = ((i + j) % 2 == 0) ? 1 : -1; //sign of adj[j][i] positive if sum of row and column indexes is even.
            adj[j][i] = (s) * (findDet(t, num - 1)); //Interchange rows and columns to get the transpose of the cofactor matrix
        }
    }
}

void InvFunc(int M[NUMSQ][NUMSQ], float inv[NUMSQ][NUMSQ], int n,bool &check) 
{
    int det = findDet(M, n);
    if (det == 0)
    {
        cout << "\nDeterminant is Zero,Hence not inversible\n";
        check = false;
        return ;
    }
    int adj[NUMSQ][NUMSQ]; 

    MatAdj(M, adj,n);// need to adjust this function or just paste it here, col and row problem at declaration

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            inv[i][j] = adj[i][j] / static_cast<float>(det);
    check = true;
    return ;
}


//Matrix determinant driver

void detDriverFunc(int arr[NUMSQ][NUMSQ], userHistory* ptr)
{
    int row, col;
    string id = "Determinant";
    cout << "Enter the number of row and column (only square matrix m x m): ";
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
    int Answer = findDet(arr, row);
    // only square matrix , so row=col
    cout<<"The Determinant of ["<<row<<"]["<<col<<"] matrix is "<< Answer<<"\n";

    //dummy array is just a place holder since function fillStruct required 2 int input array
    int dummyArray[NUMSQ][NUMSQ];
    initialize(dummyArray, NUMSQ, NUMSQ);
    float ans2[NUMSQ][NUMSQ];
    initialize(ans2, NUMSQ, NUMSQ);
    ans2[0][0] = Answer;
    
    fillStruct(arr, dummyArray, ans2, id, ptr,NUMSQ,NUMSQ);
    
    ptr = NULL;

    return;
}

//Matrix transpose driver
void transposeMat(int arr[NUMSQ][NUMSQ], int arr2[NUMSQ][NUMSQ], userHistory* ptr)
{   
    string id = "Transpose";
    initialize(arr, NUMSQ, NUMSQ);
    initialize(arr2, NUMSQ, NUMSQ);

    int row, col;
    cout << "Enter the number of row and column (m x n --> n x m): ";
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
            cout << setw(10) << arr2[i][j] ;
        cout << endl;
    }
    int dummyArray[NUMSQ][NUMSQ];
    
    initialize(dummyArray, NUMSQ, NUMSQ);
    float ans2[NUMSQ][NUMSQ];
    convertToFloatArray(arr2, ans2);
    fillStruct(arr, dummyArray, ans2, id, ptr,NUMSQ,NUMSQ);
    ptr = NULL;
    return;
}

//Matrix Addition & subtraction
void matAdd(int a[][NUMSQ], int b[][NUMSQ], int sum[][NUMSQ], userHistory* ptr)
{   
    initialize(a, NUMSQ, NUMSQ);
    initialize(b, NUMSQ, NUMSQ);
    initialize(sum, NUMSQ, NUMSQ);

    int i, j, row1, row2, col1, col2;
    string id = "Matrix_Addition";

    cout << "Enter the row and column for matrix 1 (row1 == row2, col1 ==col2): ";
    cin >> row1 >> col1;


    cout << "Enter the row and column for matrix 2 (row1 == row2, col1 ==col2): ";
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
    
    float ans2[NUMSQ][NUMSQ];
    convertToFloatArray(sum, ans2);
    
    fillStruct(a, b, ans2, id, ptr,NUMSQ,NUMSQ);
    ptr = NULL;
    return;
}

void matSubtraction(int a[][NUMSQ], int b[][NUMSQ], int sub[][NUMSQ], userHistory* ptr)
{

    initialize(a, NUMSQ, NUMSQ);
    initialize(b, NUMSQ, NUMSQ);
    initialize(sub, NUMSQ, NUMSQ);

    int i, j, row1, row2, col1, col2;
    string id = "Matrix_Subtraction";

    cout << "Enter the row and column for matrix 1 (row1 == row2, col1 ==col2): ";
    cin >> row1 >> col1;


    cout << "Enter the row and column for matrix 2 (row1 == row2, col1 ==col2): ";
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
    
    float ans2[NUMSQ][NUMSQ];
    convertToFloatArray(sub, ans2);
   
    fillStruct(a, b, ans2, id, ptr,NUMSQ,NUMSQ);
    ptr = NULL;
    return;
}

//Matrix Power
void matPower(int ans[NUMSQ][NUMSQ], userHistory* ptr)
{   
    int original[NUMSQ][NUMSQ];
    int container[NUMSQ][NUMSQ];

    initialize(ans, NUMSQ, NUMSQ);
    initialize(original, NUMSQ, NUMSQ);
    initialize(container, NUMSQ, NUMSQ);

    string id = "Matrix_Power";
    int row, col;
    cout << "Enter the number of row and column (m x m only): ";
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
        createIdenMat(ans,row,col);
        print(ans, row, col);
       
    }
    else if (userInput==1)
    {
        cout << "The answer is: \n";
        print(original, row, col);
        matCopy(ans, original);
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
    initialize(container,NUMSQ,NUMSQ);
    float ans2[NUMSQ][NUMSQ];
    convertToFloatArray(ans, ans2);
    fillStruct(original, container, ans2, id, ptr,NUMSQ,NUMSQ);

    ptr = NULL;
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
// fill the struct function 
// Reside in each Driver Fn
void fillStruct(int arr[NUMSQ][NUMSQ], int arr2[NUMSQ][NUMSQ], float arrO[NUMSQ][NUMSQ],string id, userHistory* ptr,int row,int col)
{   
    //input operation id
    ptr->operationID = id;
    // input array 1
    initialiseStructArr( ptr);// initialise all array;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            ptr->inArray[i][j] = arr[i][j];
        }
            
    }
    //input array 2
   
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            ptr->inArray2[i][j] = arr2[i][j];
        }
            
    }
    //output array
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            ptr->OutArray[i][j] = arrO[i][j];
        }
            
    }

    ptr = NULL;
    return;
}

void initialiseStructArr(userHistory* ptr)
{   
    for (int i = 0; i < NUMSQ; i++)
    {
        for (int j = 0; j < NUMSQ; j++)
        {
            ptr->inArray[i][j] = 0;
            ptr->inArray2[i][j] = 0;
            ptr->OutArray[i][j] = 0;


        }
            
    }

    ptr = NULL;
    return;
}

void convertToFloatArray(int arr[NUMSQ][NUMSQ],float arrF[NUMSQ][NUMSQ])
{
    for (int i = 0; i < NUMSQ; i++)
    {
        for (int j = 0; j < NUMSQ; j++)
            arrF[i][j] = static_cast<float>(arr[i][j]);
    }


    return;
}

void printStruct( userHistory* ptr,int index)
{   
    //print 
    for (int i = 0; i < index; i++)
    {
        cout << "Index Position :"<<(ptr + i)->position << "\tOperation: "
            << (ptr + i)->operationID << endl;
        cout << "\n-----------------------------------------------------\n";
        cout << "First Input Array :\n";
        for (int j = 0; j < NUMSQ; ++j)
        {
            for (int k = 0; k < NUMSQ; ++k)
            {
                cout << setw(10) << (ptr + i)->inArray[j][k] ;

            }
            cout << endl;
        }
        cout << "\n-----------------------------------------------------\n";
        cout <<"Second Input Array :\n"  ;
        for (int j = 0; j < NUMSQ; ++j)
        {
            for (int k = 0; k < NUMSQ; ++k)
            {
                cout << setw(10) << (ptr + i)->inArray2[j][k] ;

            }
            cout << endl;
        }
        cout << "\n-----------------------------------------------------\n";
        cout << "Output Array(for determinant the element at array[0][0] is the answer)\n";
        for (int j = 0; j < NUMSQ; ++j)
        {
            for (int k = 0; k < NUMSQ; ++k)
            {
                cout << setw(10) << (ptr + i)->OutArray[j][k] ;

            }
            cout << endl;
        }
        cout << "\n-----------------------------------------------------\n";
    }
    cout << "\nDo you want to print the history list? Y/N\n";
    char ch3;
    cin >> ch3;
    if (toupper(ch3) == 'Y')
    {

        printFile(ptr, index);

    }
    ptr = NULL;
    return;
}

void initialize(float ans[NUMSQ][NUMSQ], int row, int col)
{
    //cout << "Initialize the matrix " << endl;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            ans[i][j] = 0;
        }


    return;
}
void updateStruct(userHistory* ptr, int current, int search)//current is already +1 than the last position
{   
    int product[NUMSQ][NUMSQ], arr1[NUMSQ][NUMSQ], arr2[NUMSQ][NUMSQ];
    float inverseMat[NUMSQ][NUMSQ];
    int userChoice;

    if (search >= current && search < 0)
    {
        cout << "\nThe Position is out of the range.Exiting..\n";
        return;
    }
    else
    {
        for (int i = 0; i < current; i++)
        {
            if ((ptr + i)->position == search)
            {
                cout << "List of Matrix Operation :\n"
                    << "1.Matrix Multiplication\n"
                    << "2.Matrix Inverse\n"
                    << "3.Matrix Transpose\n"
                    << "4.Matrix Addition\n"
                    << "5.Matrix Subtraction\n"
                    << "6.Matrix Power\n"
                    << "7.Matrix Determinant\n"
                    << "Enter your option (1-7) :";

                cin >> userChoice;

                switch (userChoice)
                {
                case 1:
                    multMatrix(arr1, arr2, product, (ptr + search));
                    (ptr + search)->position = search;
                   
                    break;
                case 2:
                    invMatDriver(arr1, inverseMat, (ptr + search));
                    (ptr + search)->position = search;
                    break;
                case 3:
                    transposeMat(arr1, arr2, (ptr + search));
                    (ptr + search)->position = search;
                    break;
                case 4:
                    matAdd(arr1, arr2, product, (ptr + search));
                    (ptr + search)->position = search;
                    break;
                case 5:
                    matSubtraction(arr1, arr2, product, (ptr + search));
                    (ptr + search)->position = search;
                    break;
                case 6:
                    matPower(product, (ptr + search));
                    (ptr + search)->position = search;
                    break;
                case 7:
                    detDriverFunc(arr1, (ptr + search));
                    (ptr + search)->position = search;
                    break;
               
                default:
                    cout << "\nNot a valid option\n";


                }
            }

        }

    }

    return;
}

void resetStruct(userHistory*& ptrK, int& index, int histNum2 )
{
    delete[] ptrK;
    ptrK = NULL;
    index = 0;
    ptrK = new userHistory[histNum2];

    return;
}

void printFile( userHistory* ptrK,  int index)
{
    ifstream openF;
    ofstream writeF;

    cout << "Name Your file: ";
    string fileName;
    cin >> fileName;
    openF.open(fileName.c_str());

    if (!openF.fail())
    {
        cout << "\nFile is already existed \n"
        << "Do you want to overwrite Y/N :";
        char ch;
        cin >> ch;
        
        if (toupper(ch) == 'N')
            return;
    }
    openF.close();
    writeF.open(fileName.c_str());

    if (writeF.fail())
    {
        cout << "Opening failed.Exiting..\n";
        return;

    }
    for (int i = 0; i < index; i++)
    {
        writeF << "Index Position :" << (ptrK + i)->position << "\tOperation: "
            << (ptrK + i)->operationID << endl;
        writeF << "\n-----------------------------------------------------\n";
        writeF << "First Input Array :\n";
        for (int j = 0; j < NUMSQ; ++j)
        {
            for (int k = 0; k < NUMSQ; ++k)
            {
                writeF << setw(10) << (ptrK + i)->inArray[j][k] ;

            }
            writeF << endl;
        }
        writeF << "\n-----------------------------------------------------\n";
        writeF << "Second Input Array :\n";
        for (int j = 0; j < NUMSQ; ++j)
        {
            for (int k = 0; k < NUMSQ; ++k)
            {
                writeF << setw(10) << (ptrK + i)->inArray2[j][k] ;

            }
            writeF << endl;
        }
        writeF << "\n-----------------------------------------------------\n";
        writeF << "Output Array(for determinant the element at array[0][0] is the answer)\n";
        for (int j = 0; j < NUMSQ; ++j)
        {
            for (int k = 0; k < NUMSQ; ++k)
            {
                writeF << setw(10) << (ptrK + i)->OutArray[j][k] ;

            }
            writeF << endl;
        }
        writeF << "\n-----------------------------------------------------\n";
    }
    ptrK = NULL;

    writeF.close();

    return;
}
