#include <iostream>
#include<vector>
#include<climits>
using namespace std;
#define INF INT_MAX

int count_stages(vector<vector<int>>& graph) {
    int size = graph.size();
    vector<int> stage(size, 0);             // stage of each vertex

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (graph[i][j] != INF && graph[i][j]!=0) {
                stage[j] = stage[i] + 1;            // coz in a MSG; an edge exists only between Stage x and Stage x+1
            }                                       // toh j vertex toh immediate next stage mein hi hogi !!! :D
        }
    }

    int max_stages = 0;
    for (int i = 0; i < size; i++) {
        if (stage[i] > max_stages) {
            max_stages = stage[i];
        }
    }

    for(int i=0; i<size; i++){
        cout<<"Stage of vertex "<<i<<" is -: "<<stage[i]<<endl;
    }

    return max_stages + 1; // for the final vertex (sink)
}


int BMG(vector<vector<int>>& graph, int stages, int nodes) {
    vector<int> bdist(nodes, INF);
    vector<int> d(nodes, -1);

    bdist[0] = 0;

    for (int j = 1; j < nodes; j++) {
        for (int i = 0; i < j; i++) {
            if (graph[i][j] != INF && graph[i][j] != 0) {
                if (graph[i][j] + bdist[i] < bdist[j]) {
                    bdist[j] = graph[i][j] + bdist[i];
                    d[j] = i;
                }
            }
        }
    }

    vector<int> path(stages, -1);
    path[stages - 1] = nodes - 1;

    for (int j = stages - 2; j >= 0; j--) {
        path[j] = d[path[j + 1]];
    }

    cout << "Minimum-cost path: ";
    for (int vertices : path) {
        if (vertices != -1) cout << vertices << " ";
    }
    cout << endl;

    return bdist[nodes - 1];
}

int main() {
    vector<vector<int>> graph = {
        //  0  1  2  3  4  5  6  7  
          { 0, 7, 5, 1, INF, INF, INF, INF }, // 0
          { INF, 0, INF, INF, 2, 3, INF, INF }, // 1
          { INF, INF, 0, INF, 6, 7, INF, INF }, // 2
          { INF, INF, INF, 0, 4, 8, 9, INF }, // 3
          { INF, INF, INF, INF, 0, INF, INF, 6 }, // 4
          { INF, INF, INF, INF, INF, 0, INF, 4 }, // 5
          { INF, INF, INF, INF, INF, INF, 0, 2 }, // 6
          { INF, INF, INF, INF, INF, INF, INF, 0 } // 7
      };

      int size = graph.size();

    // cout << "Stages in the graph are = " << count_stages(graph) << endl;

    int res = count_stages(graph);

    int min_cost = BMG(graph, res, size);
    cout << "Minimum Cost to reach sink: " << min_cost << endl;


    return 0;
}