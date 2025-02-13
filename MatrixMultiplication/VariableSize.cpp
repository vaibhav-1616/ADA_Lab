#include <iostream>
#include<vector>
using namespace std;

// Function to perform matrix multiplication

void mm(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C){
    int rows_ofA = A.size();
    int cols_ofB = B[0].size();
    int cols_ofA = A[0].size();

    for(int i=0; i<rows_ofA; i++){
        for(int j=0; j<cols_ofB; j++){
            C[i][j] = 0;
            for(int k=0; k<cols_ofA; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void print(vector<vector<int>> matrix){
    for(auto& row: matrix){
        for(int val: row){
            cout<<val<<" ";
        }
        cout<<endl;
    }
}

int main() {

    // int rows = 2;
    // int cols = 3;

    // vector<vector<int>> matrix (rows, vector<int> (cols, 0));

    // this is a vector of vectors such that outer vector forms the rows of the matrix and the inner vector forms the columns which are all initialized to 0; outer vector has been initialized with rows... inner vector for columns...

    vector<vector<int>> A = {{1,2,3}, {4,5,6}}; // 2x3 matrix
    
    vector<vector<int>> B = {{1,2}, {3,4}, {5,6}};  // 3x2 matrix

    vector<vector<int>> C(2, vector<int> (2,0)) ;      // this will be 2x2 matrix

    mm(A, B, C);

    cout<<"Matrix C:"<<endl;
    print(C);
    
    return 0;
}
