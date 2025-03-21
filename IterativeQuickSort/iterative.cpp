#include <iostream>
#include <stack>
#include <vector>
#include <chrono>  // For timing
#include<fstream>

using namespace std;
using namespace std::chrono;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j=low; j<high; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[high], arr[i+1]);
    return i+1;

}

void Iterativequicksort(vector<int> &arr, int low, int high){
    stack<int> s;

    s.push(low);
    s.push(high);

    while(!s.empty()){
        high = s.top();
        s.pop();
        low = s.top();
        s.pop();

        if(low<high){
            int p = partition(arr, low, high);
            s.push(low);
            s.push(p-1);

            s.push(p+1);
            s.push(high);
        }
    }
}


int main() {

    ofstream file("iterative.csv");
    file << "size,time\n";

    for (int n = 100000; n <= 1000000; n += 100000) { 
        vector<int> arr(n);

        // Fill array with random numbers
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % 900001 + 100000;
        }

        auto start = high_resolution_clock::now(); // Start time
        Iterativequicksort(arr, 0, n - 1);
        auto end = high_resolution_clock::now();   // End time

        long long duration = duration_cast<nanoseconds>(end - start).count();

        // cout << "Time taken by QuickSort for " << n << " elements: " << duration << " microseconds" << endl;
        file << n << "," << duration << "\n";
        // cout << "n = " << n << ", Time = " << duration << " ns\n";
    }

    file.close();

    return 0;
}