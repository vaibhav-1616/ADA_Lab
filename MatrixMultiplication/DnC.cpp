#include <iostream>
#include <vector>
using namespace std;

// DnC Approach: using recursive calls
void mm(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& C, int size)
{
    if (size <= 2)
    {
        C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
        C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
        C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
        C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
    }
    else
    {
        int mid = size / 2;

        // Create extra matrices to store elements in sub-matrices
        // int A11[2][2], A12[2][2], A21[2][2], A22[2][2];
        // int B11[2][2], B12[2][2], B21[2][2], B22[2][2];
        // int C11[2][2], C12[2][2], C21[2][2], C22[2][2];

        vector<vector<int>> A11(mid, vector<int>(mid, 0)), 
                            A12(mid, vector<int>(mid, 0)), 
                            A21(mid, vector<int>(mid, 0)), 
                            A22(mid, vector<int>(mid, 0));

        vector<vector<int>> B11(mid, vector<int>(mid, 0)), 
                            B12(mid, vector<int>(mid, 0)), 
                            B21(mid, vector<int>(mid, 0)), 
                            B22(mid, vector<int>(mid, 0));

        vector<vector<int>> C11(mid, vector<int>(mid, 0)), 
                            C12(mid, vector<int>(mid, 0)), 
                            C21(mid, vector<int>(mid, 0)), 
                            C22(mid, vector<int>(mid, 0));

        for(int i = 0; i < mid; i++)
        {
            for(int j = 0; j < mid; j++)
            {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + mid];
                A21[i][j] = A[i + mid][j];
                A22[i][j] = A[i + mid][j + mid];

                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + mid];
                B21[i][j] = B[i + mid][j];
                B22[i][j] = B[i + mid][j + mid];
            }
        }

        // Multiply the sub-matrices
        vector<vector<int>> temp1(mid, vector<int>(mid, 0)), temp2(mid, vector<int>(mid, 0));

        // 1. A11*B11 + A12*B21
        mm(A11, B11, temp1, mid);
        mm(A12, B21, temp2, mid);
        for(int i = 0; i < mid; i++)
        {
            for(int j = 0; j < mid; j++)
            {
                C11[i][j] = temp1[i][j] + temp2[i][j];
            }
        }

        // 2. A11*B12 + A12*B22
        mm(A11, B12, temp1, mid);
        mm(A12, B22, temp2, mid);
        for(int i = 0; i < mid; i++)
        {
            for(int j = 0; j < mid; j++)
            {
                C12[i][j] = temp1[i][j] + temp2[i][j];
            }
        }

        // 3. A21*B11 + A22*B21
        mm(A21, B11, temp1, mid);
        mm(A22, B21, temp2, mid);
        for(int i = 0; i < mid; i++)
        {
            for(int j = 0; j < mid; j++)
            {
                C21[i][j] = temp1[i][j] + temp2[i][j];
            }
        }

        // 4. A21*B12 + A22*B22
        mm(A21, B12, temp1, mid);
        mm(A22, B22, temp2, mid);
        for(int i = 0; i < mid; i++)
        {
            for(int j = 0; j < mid; j++)
            {
                C22[i][j] = temp1[i][j] + temp2[i][j];
            }
        }

        // Final Result
        for(int i = 0; i < mid; i++)
        {
            for(int j = 0; j < mid; j++)
            {
                C[i][j] = C11[i][j];
                C[i][j + mid] = C12[i][j];
                C[i + mid][j] = C21[i][j];
                C[i + mid][j + mid] = C22[i][j];
            }
        }
    }
}

int main()
{
    vector<vector<int>> matrix1 = {
        {5, 3, 7, 5},
        {9, 8, 5, 1},
        {2, 4, 3, 6},
        {6, 4, 4, 2}
    };

    vector<vector<int>> matrix2 = {
        {5, 9, 4, 2},
        {8, 1, 5, 2},
        {7, 4, 1, 4},
        {8, 3, 7, 1}
    };

    vector<vector<int>> matrix3(4, vector<int>(4, 0)); // Result matrix initialized with zeros

    mm(matrix1, matrix2, matrix3, 4); // Using matrix3 to store the result

    cout << "Result of Matrix Multiplication:" << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << matrix3[i][j] << " "; // Output the result matrix
        }
        cout << endl;
    }

    return 0;
}
