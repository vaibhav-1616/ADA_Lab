#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <cmath>

using namespace std;
using namespace std::chrono;

int partition(vector<int>& arr, int l, int h){
    int pivot = arr[l];
    int i = l+1; 
    int j = h;

    while(true){
        while(i <= j && arr[i] <= pivot) i++;
        while(i <= j && arr[j] > pivot) j--;
        if(i >= j) break;
        swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]);
    return j;
}

void quicksort(vector<int> &arr, int l, int h){
    if(l < h){
        int p = partition(arr, l, h);
        quicksort(arr, l, p-1);
        quicksort(arr, p+1, h);
    }
}

int main() {
    ofstream file("quicksort_runtime.csv");
    file << "n,runtime_microseconds\n"; // CSV Headers

    srand(time(0));

    for(int n = 10000; n <= 100000; n += 10000){
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            arr[i] = rand() % 90001 + 10000;
        }

        cout << "Sorting for n = " << n << "...\n";

        auto start = high_resolution_clock::now();
        quicksort(arr, 0, n-1);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        // Write results to CSV file
        file << n << "," << duration.count() << "\n";
    }

    file.close();
    cout << "Data saved to quicksort_runtime.csv\n";
    return 0;
}
