#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

// Find function with path compression
int Find(vector<int> &parent, int u) {
    if (parent[u] < 0) return u;
    return parent[u] = Find(parent, parent[u]);
}

// Union function to merge sets
void Union(vector<int> &parent, int u, int v) {
    int rootU = Find(parent, u);
    int rootV = Find(parent, v);

    if (rootU != rootV) parent[rootV] = rootU;
}

// Kruskal's Algorithm
float Kruskal(vector<tuple<int, int, int>> &E, int n, vector<vector<int>> &t) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> heap(E.begin(), E.end());
    vector<int> parent(n, -1);
    int i = 0;
    float mincost = 0.0;

    while (i < n - 1 && !heap.empty()) {
        tuple<int, int, int> edge = heap.top();
        heap.pop();
    
        int cost = get<0>(edge);
        int u = get<1>(edge);
        int v = get<2>(edge);
    
        int j = Find(parent, u);
        int k = Find(parent, v);
    
        if (j != k) {
            t[i][0] = u;
            t[i][1] = v;
            mincost += cost;
            Union(parent, j, k);
            i++;
        }
    }
    

    if (i != n - 1) {
        cout << "No spanning tree" << endl;
        return -1; // Indicating failure
    }
    return mincost;
}

// Driver Code
int main() {
    int n = 5; // Number of vertices
    vector<tuple<int, int, int>> edges = {
        {10, 0, 1}, {20, 0, 2}, {30, 1, 2},
        {5, 1, 3}, {15, 2, 3}, {6, 3, 4}
    };

    vector<vector<int>> t(n - 1, vector<int>(2)); // Solution array (n-1)x2
    float mincost = Kruskal(edges, n, t);

    if (mincost != -1) {
        cout << "Minimum Spanning Tree edges:\n";
        for (auto &edge : t) cout << edge[0] << " - " << edge[1] << endl;
        cout << "Total Cost: " << mincost << endl;
    }

    return 0;
}
