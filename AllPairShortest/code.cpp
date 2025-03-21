#include <iostream>
#include <vector>
#include<climits>
using namespace std;

#define INF INT_MAX
#define V 5      // Number of vertices


void AllPairShortest(vector<vector<int>> &graph, vector<vector<int>> &A, int n) {
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < n; k++) {      // Intermediate vertex
        for (int i = 0; i < n; i++) {  // Source vertex
            for (int j = 0; j < n; j++) { // Destination vertex
                if (A[i][k] != INF && A[k][j] != INF) { 
                    A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
                }
            }
        }
    }
}


void printSolution(const vector<vector<int>> &A, int n) {
    cout << "All-Pairs Shortest Path Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == INF)
                cout << "INF ";
            else
                cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 4, INF, 5, INF},
        {INF, 0, 1, INF, 6},
        {2, INF, 0, 3, INF},
        {INF, INF, 1, 0, 2},
        {1, INF, INF, 4, 0}
    };

    vector<vector<int>> A(V, vector<int>(V, INF)); 

    AllPairShortest(graph, A, V);

    printSolution(A, V);

    return 0;
}
