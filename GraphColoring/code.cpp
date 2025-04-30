#include <iostream>
#include <vector>
using namespace std;

#define V 4

bool isValid(int node, int col, const vector<vector<int>> &graph, const vector<int> &color) {
    for (int i = 0; i < V; i++) {
        if (graph[node][i] == 1 && color[i] == col)
            return false;
    }
    return true;
}

bool solve(int node, int m, const vector<vector<int>> &graph, vector<int> &color) {
    if (node == V) return true;

    for (int c = 1; c <= m; c++) {
        if (isValid(node, c, graph, color)) {
            color[node] = c;
            if (solve(node + 1, m, graph, color))
                return true;
            color[node] = 0; // backtrack
        }
    }
    return false;
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3;  // Number of colors
    vector<int> color(V, 0);

    if (solve(0, m, graph, color)) {
        cout << "Color assignment:\n";
        for (int i = 0; i < V; i++)
            cout << "Vertex " << i << " -> Color " << color[i] << "\n";
    } else {
        cout << "No solution.\n";
    }

    return 0;
}
