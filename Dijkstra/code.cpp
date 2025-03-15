#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define V 5

int minDistance(vector<int>& dist, vector<bool>& sptSet) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printSolution(vector<int>& dist) {
    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << " \t\t " << dist[i] << "\n";
    }
}

void dijkstra(vector<vector<int>>& graph, int src) {
    vector<int> dist(V, INT_MAX); // The output array. dist[i] will hold the shortest distance from src to i
    vector<bool> sptSet(V, false); // sptSet[i] will be true if vertex i is included in shortest path

    dist[src] = 0; // Distance of source vertex from itself is always 0

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);  // Pick the minimum distance vertex from the set of vertices not yet processed
        sptSet[u] = true;                   // Mark the picked vertex as processed

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 0, 0, 5},
        {0, 0, 1, 0, 2},
        {0, 0, 0, 4, 0},
        {7, 0, 6, 0, 0},
        {0, 3, 9, 2, 0}
    };

    dijkstra(graph, 0);     // source vertex is 0

    return 0;
}