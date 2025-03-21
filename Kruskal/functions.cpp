#include <iostream>
#include<vector>
using namespace std;

#define V 5

vector<int> parent(V, -1);

int find(int u){
    while(parent[u]>=0){
        u = parent[u];
    }
    return u;
}

void unionsets(int u, int v){
    int root_ofU = find(u);
    int root_ofV = find(v);

    if(root_ofU!=root_ofV){
        parent[u] = v;
    }
}


void heapify(int arr[], int n, int i) {
    int smallest = i;       // Assume root (i) is the smallest
    int left = 2 * i + 1;   // Left child index
    int right = 2 * i + 2;  // Right child index

    // If left child is smaller than root
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // If right child is smaller than smallest so far
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If smallest is not root, swap and heapify the affected subtree
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);  // Recursively heapify the affected subtree
    }
}


void buildMinHeap(int arr[], int n) {
    // Start from the last non-leaf node and heapify each node
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}


void printHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    
    // for(int i=0; i<V; i++){
    //     cout<<"Parent of "<<i<<" = "<<parent[i]<<endl;
    // }

    unionsets(0,1);
    unionsets(1,2);
    unionsets(2,3);
    unionsets(3,4);


    for(int i=0; i<V; i++){
        cout<<"Parent of "<<i<<" = "<<parent[i]<<endl;
    }

    cout << "Find(2): " << find(2) << endl; 
    cout << "Find(3): " << find(3) << endl; 

    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };


    return 0;
}