#include <iostream>
using namespace std;

// Function to perform matrix multiplication

void mm(int A[2][3], int B[3][2], int C[2][2]){
    for(int i=0; i<2; i++){                 // outer for loop will run for times equal to number of rows of A
        for(int j=0; j<2; j++){             // inner for loop will run for times equal to number of columns of B
            C[i][j] = 0;
            for(int k=0; k<3; k++){         // loop for times equal to columns of A
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void print(int arr[2][2]){
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    // Define two 2x2 matrices A and B
    int A[2][3] = {{1, 2, 3}, {3, 4, 5}};
    int B[3][2] = {{1, 4}, {2, 5}, {3,6}};
    int C[2][2];  
    
    mm(A, B, C);
    
    cout << "Resulting matrix C (A * B):" << endl;
    print(C);
    
    return 0;
}
