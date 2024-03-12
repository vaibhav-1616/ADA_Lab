#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <cstdlib>

using namespace std;
using namespace chrono;

void add(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtract(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int size) {
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int mid = size / 2;
    vector<vector<int>> A11(mid, vector<int>(mid)), A12(mid, vector<int>(mid)),
                        A21(mid, vector<int>(mid)), A22(mid, vector<int>(mid)),
                        B11(mid, vector<int>(mid)), B12(mid, vector<int>(mid)),
                        B21(mid, vector<int>(mid)), B22(mid, vector<int>(mid)),
                        C11(mid, vector<int>(mid)), C12(mid, vector<int>(mid)),
                        C21(mid, vector<int>(mid)), C22(mid, vector<int>(mid)),
                        M1(mid, vector<int>(mid)), M2(mid, vector<int>(mid)),
                        M3(mid, vector<int>(mid)), M4(mid, vector<int>(mid)),
                        M5(mid, vector<int>(mid)), M6(mid, vector<int>(mid)),
                        M7(mid, vector<int>(mid)), AResult(mid, vector<int>(mid)),
                        BResult(mid, vector<int>(mid));

    for (int i = 0; i < mid; i++)
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

    add(A11, A22, AResult, mid); add(B11, B22, BResult, mid); strassen(AResult, BResult, M1, mid);
    add(A21, A22, AResult, mid); strassen(AResult, B11, M2, mid);
    subtract(B12, B22, BResult, mid); strassen(A11, BResult, M3, mid);
    subtract(B21, B11, BResult, mid); strassen(A22, BResult, M4, mid);
    add(A11, A12, AResult, mid); strassen(AResult, B22, M5, mid);
    subtract(A21, A11, AResult, mid); add(B11, B12, BResult, mid); strassen(AResult, BResult, M6, mid);
    subtract(A12, A22, AResult, mid); add(B21, B22, BResult, mid); strassen(AResult, BResult, M7, mid);

    add(M1, M4, AResult, mid); subtract(AResult, M5, BResult, mid); add(BResult, M7, C11, mid);
    add(M3, M5, C12, mid); add(M2, M4, C21, mid);
    add(M1, M3, AResult, mid); subtract(AResult, M2, BResult, mid); add(BResult, M6, C22, mid);

    for (int i = 0; i < mid; i++)
        for (int j = 0; j < mid; j++) {
            C[i][j] = C11[i][j]; C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j]; C[i + mid][j + mid] = C22[i][j];
        }
}

int main() {
    ofstream outfile("strassen_data.csv");
    outfile << "size,time\n";

    for (int size = 2; size <= 300; size *= 2) {
        vector<vector<int>> A(size, vector<int>(size)), B(size, vector<int>(size)), C(size, vector<int>(size));

        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j) {
                A[i][j] = rand() % 10;
                B[i][j] = rand() % 10;
            }

        auto start = high_resolution_clock::now();
        strassen(A, B, C, size);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);  // Save in ns

        cout << "Size: " << size << " Time: " << duration.count() << " ms" << endl;
        outfile << size << "," << duration.count() << "\n";
    }

    outfile.close();
    return 0;
}
