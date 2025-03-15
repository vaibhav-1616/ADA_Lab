#include <iostream>
#include <vector>
using namespace std;

// Function to add two matrices
void add(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& C, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subtract(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& C, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Strassen's matrix multiplication algorithm
void strassen(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& C, int size) {
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
    } else {
        int mid = size / 2;

        vector<vector<int>> A11(mid, vector<int>(mid, 0)), A12(mid, vector<int>(mid, 0)), A21(mid, vector<int>(mid, 0)), A22(mid, vector<int>(mid, 0));
        vector<vector<int>> B11(mid, vector<int>(mid, 0)), B12(mid, vector<int>(mid, 0)), B21(mid, vector<int>(mid, 0)), B22(mid, vector<int>(mid, 0));
        vector<vector<int>> C11(mid, vector<int>(mid, 0)), C12(mid, vector<int>(mid, 0)), C21(mid, vector<int>(mid, 0)), C22(mid, vector<int>(mid, 0));
        vector<vector<int>> M1(mid, vector<int>(mid, 0)), M2(mid, vector<int>(mid, 0)), M3(mid, vector<int>(mid, 0)), M4(mid, vector<int>(mid, 0));
        vector<vector<int>> M5(mid, vector<int>(mid, 0)), M6(mid, vector<int>(mid, 0)), M7(mid, vector<int>(mid, 0));
        vector<vector<int>> AResult(mid, vector<int>(mid, 0)), BResult(mid, vector<int>(mid, 0));

        // Dividing the matrices into sub-matrices
        for (int i = 0; i < mid; i++) {
            for (int j = 0; j < mid; j++) {
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

        // Calculating M1 to M7
        add(A11, A22, AResult, mid); // A11 + A22
        add(B11, B22, BResult, mid); // B11 + B22
        strassen(AResult, BResult, M1, mid); // M1 = (A11 + A22) * (B11 + B22)

        add(A21, A22, AResult, mid); // A21 + A22
        strassen(AResult, B11, M2, mid); // M2 = (A21 + A22) * B11

        subtract(B12, B22, BResult, mid); // B12 - B22
        strassen(A11, BResult, M3, mid); // M3 = A11 * (B12 - B22)

        subtract(B21, B11, BResult, mid); // B21 - B11
        strassen(A22, BResult, M4, mid); // M4 = A22 * (B21 - B11)

        add(A11, A12, AResult, mid); // A11 + A12
        strassen(AResult, B22, M5, mid); // M5 = (A11 + A12) * B22

        subtract(A21, A11, AResult, mid); // A21 - A11
        add(B11, B12, BResult, mid); // B11 + B12
        strassen(AResult, BResult, M6, mid); // M6 = (A21 - A11) * (B11 + B12)

        subtract(A12, A22, AResult, mid); // A12 - A22
        add(B21, B22, BResult, mid); // B21 + B22
        strassen(AResult, BResult, M7, mid); // M7 = (A12 - A22) * (B21 + B22)

        // Calculating C11, C12, C21, C22
        add(M1, M4, AResult, mid); // M1 + M4
        subtract(AResult, M5, BResult, mid); // M1 + M4 - M5
        add(BResult, M7, C11, mid); // C11 = M1 + M4 - M5 + M7

        add(M3, M5, C12, mid); // C12 = M3 + M5

        add(M2, M4, C21, mid); // C21 = M2 + M4

        add(M1, M3, AResult, mid); // M1 + M3
        subtract(AResult, M2, BResult, mid); // M1 + M3 - M2
        add(BResult, M6, C22, mid); // C22 = M1 + M3 - M2 + M6

        // Combining the results into a single matrix
        for (int i = 0; i < mid; i++) {
            for (int j = 0; j < mid; j++) {
                C[i][j] = C11[i][j];
                C[i][j + mid] = C12[i][j];
                C[i + mid][j] = C21[i][j];
                C[i + mid][j + mid] = C22[i][j];
            }
        }
    }
}

int main() {
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

    strassen(matrix1, matrix2, matrix3, 4); // Using matrix3 to store the result

    cout << "Result of Matrix Multiplication:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matrix3[i][j] << " "; // Output the result matrix
        }
        cout << endl;
    }

    return 0;
}