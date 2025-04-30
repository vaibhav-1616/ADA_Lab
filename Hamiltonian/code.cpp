#include <iostream>
#include <vector>
using namespace std;

#define V 5

bool isSafe(int v, const vector<vector<int>> &graph, const vector<int> &path, int pos) {
    if (graph[path[pos - 1]][v] == 0) return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamiltonianUtil(const vector<vector<int>> &graph, vector<int> &path, int pos) {
    if (pos == V) {
        return graph[path[pos - 1]][path[0]] == 1; // Check cycle
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamiltonianUtil(graph, path, pos + 1))
                return true;
            path[pos] = -1; // backtrack
        }
    }
    return false;
}

void hamiltonianCycle(const vector<vector<int>> &graph) {
    vector<int> path(V, -1);
    path[0] = 0;

    if (hamiltonianUtil(graph, path, 1)) {
        cout << "Hamiltonian Cycle: ";
        for (int i = 0; i < V; i++)
            cout << path[i] << " ";
        cout << path[0] << endl; // To complete the cycle
    } else {
        cout << "No Hamiltonian Cycle exists.\n";
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    hamiltonianCycle(graph);
    return 0;
}
