#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define V 5

pair<int, int> findMinWeightEdge(const vector<vector<int>> &graph, int &minWeight)
{
    minWeight = INT_MAX;
    int u = -1, v = -1;

    for (int i = 0; i < V; i++)
    {
        for (int j = i + 1; j < V; j++)
        { // Avoid duplicate checks in undirected graph
            if (graph[i][j] < minWeight && graph[i][j] != 0)
            {
                minWeight = graph[i][j];
                u = i;
                v = j;
            }
        }
    }

    return {u, v};
}

void prims(vector<vector<int>> &graph, vector<vector<int>> &result)
{
    int n = graph.size();
    vector<int> near(n, INT_MAX);    // Tracks the nearest vertex to MST
    vector<int> minimum(n, INT_MAX); // Stores the minimum weight edge

    int minweight;
    pair<int, int> minEdge = findMinWeightEdge(graph, minweight);
    int k = minEdge.first;
    int l = minEdge.second;

    if (k == -1 || l == -1)
        return; // No valid edges

    result.push_back({k, l, graph[k][l]});
    near[k] = 0;
    near[l] = 0;

    // Initialize `near[]` properly for all vertices
    for (int i = 0; i < n; i++)
    {
        if (near[i] != 0)
        { // Only update if not in MST
            if (graph[i][k] != 0 && (graph[i][k] < graph[i][l] || graph[i][l] == 0))
                near[i] = k;
            else if (graph[i][l] != 0)
                near[i] = l;
        }
    }

    for (int i = 1; i < n - 1; i++)
    {
        int min = INT_MAX;
        int j = -1;

        // Find the minimum edge to the current MST
        for (int m = 0; m < n; m++)
        {
            if (near[m] != 0 && graph[m][near[m]] != 0 && graph[m][near[m]] < min)
            {
                min = graph[m][near[m]];
                j = m;
            }
        }

        if (j == -1)
            return; // No valid edges left

        result.push_back({j, near[j], graph[j][near[j]]});
        near[j] = 0;

        // Update near[] for all vertices
        for (int m = 0; m < n; m++)
        {
            if (near[m] != 0 && graph[m][j] != 0 && graph[m][j] < graph[m][near[m]])
            {
                near[m] = j;
            }
        }
    }
}

int main()
{
    vector<vector<int>> graph = {
        {0, 3, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 7, 7},
        {4, 3, 5, 7, 2},
        {0, 5, 7, 9, 0}};

    vector<vector<int>> result;
    prims(graph, result);

    // Print the result
    cout << "Edge \tWeight\n";
    for (const auto &edge : result)
    {
        cout << edge[0] << " - " << edge[1] << " \t" << edge[2] << " \n";
    }

    return 0;
}
