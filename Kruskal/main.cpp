#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

// Min Heap Structure
class MinHeap {
public:
    vector<tuple<int, int, int>> heap;

    // Heapify down to maintain min-heap property
    void heapifyDown(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < heap.size() && get<0>(heap[left]) < get<0>(heap[smallest])) 
            smallest = left;
        if (right < heap.size() && get<0>(heap[right]) < get<0>(heap[smallest])) 
            smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    // Heapify up (used for insertion)
    void heapifyUp(int i) {
        int parent = (i - 1) / 2;
        if (i > 0 && get<0>(heap[i]) < get<0>(heap[parent])) {
            swap(heap[i], heap[parent]);
            heapifyUp(parent);
        }
    }

    // Build the heap from the given edges
    void buildHeap(vector<tuple<int, int, int>> &edges) {
        heap = edges;
        for (int i = heap.size() / 2 - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    // Extract the minimum element
    tuple<int, int, int> extractMin() {
        if (heap.empty()) return {-1, -1, -1}; // Return invalid edge if heap is empty

        tuple<int, int, int> minEdge = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return minEdge;
    }

    // Check if the heap is empty
    bool empty() {
        return heap.empty();
    }
};

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

// Kruskal's Algorithm using Manual Min Heap
float Kruskal(vector<tuple<int, int, int>> &E, int n, vector<vector<int>> &t) {
    MinHeap heap;
    heap.buildHeap(E);

    vector<int> parent(n, -1);
    int i = 0;
    float mincost = 0.0;

    while (i < n - 1 && !heap.empty()) {
        tuple<int, int, int> edge = heap.extractMin();
        int cost = get<0>(edge);
        int u = get<1>(edge);
        int v = get<2>(edge);

        int j = Find(parent, u);
        int k = Find(parent, v);

        if (j != k) { // If they belong to different sets
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
