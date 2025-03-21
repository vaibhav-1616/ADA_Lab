#include <iostream>
#include<vector>
#include<climits>
using namespace std;

#define INF INT_MAX

int count_stages(vector<vector<int>> &graph){
    int size = graph.size();

    int stages = 0;

    for(int i=0; i<size; i++){
        bool aValidEdge = false;
        for(int j=0; j<size; j++){
            if(graph[i][j]!=INF && graph[i][j]!=0){
                aValidEdge = true;
                break;
            }
        }

        if(aValidEdge){             // if the row has a valid outgoing edge then;
            stages++;
        }
    }

    return stages;

}

int main() {
    
    vector<vector<int>> graph = {
      //  0  1  2  3  4  5  6  7  
        { 0, 7, 5, 1, INF, INF, INF, INF }, // 0
        { INF, 0, INF, INF, 2, 3, INF, INF }, // 1
        { INF, INF, 0, INF, 6, 7, INF, INF }, // 2
        { INF, INF, INF, 0, 6, 8, 9, INF }, // 3
        { INF, INF, INF, INF, 0, INF, INF, 6 }, // 4
        { INF, INF, INF, INF, INF, 0, INF, 4 }, // 5
        { INF, INF, INF, INF, INF, INF, 0, 2 }, // 6
        { INF, INF, INF, INF, INF, INF, INF, 0 } // 7
    };

    cout<<"Stages in the graph are = "<<count_stages(graph)<<endl;

    return 0;
}