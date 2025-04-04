#include <iostream>
#include <vector>
#include <climits>

#define INF INT_MAX

using namespace std;

pair<vector<vector<int>>, vector<vector<int>>> MCM(vector<int> &p) {
    int n = p.size() - 1;
    vector<vector<int>> M(n, vector<int>(n, 0));
    vector<vector<int>> S(n, vector<int>(n, -1)); // -1 to avoid infinite recursion issues

    for (int l = 2; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            int j = i + l - 1;
            M[i][j] = INF;

            for (int k = i; k < j; k++) {
                int q = M[i][k] + M[k+1][j] + p[i] * p[k+1] * p[j+1];
                if (q < M[i][j]) {
                    M[i][j] = q;
                    S[i][j] = k;
                }
            }
        }
    }

    return {S, M};
}


void print(vector<vector<int>> &S, int i, int j) {
    if (i == j) {
        cout << "A" << (i+1);  
        return;
    }

    cout << "(";
    print(S, i, S[i][j]);      
    print(S, S[i][j] + 1, j);  
    cout << ")";
}

int main() {
    vector<int> p = {10, 15, 20, 5, 10};

    auto answer = MCM(p);
    vector<vector<int>> S_array = answer.first;
    vector<vector<int>> M_array = answer.second;

    int order_of_s = S_array.size();  // Same as order of M

    cout << "\nS matrix:\n";
    for (int i = 0; i < order_of_s; i++) {
        for (int j = 0; j < order_of_s; j++) {
            cout << S_array[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nM matrix:\n";
    for (int i = 0; i < order_of_s; i++) {
        for (int j = 0; j < order_of_s; j++) {
            cout << M_array[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nOptimal Parenthesization: ";
    print(S_array, 0, order_of_s - 1);
    cout << endl;

    return 0;
}
