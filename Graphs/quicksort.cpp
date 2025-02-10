#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <cmath>

using namespace std;
using namespace std::chrono;

// Function to partition the array
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1; 

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// QuickSort function
void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    ofstream file("quicksort_runtime.csv");
    file << "n,runtime_ns,n_log_n,n_squared\n"; // CSV Headers

    // Run for different values of n
    for (int n = 100000; n <= 1000000; n += 100000) { 
        vector<int> arr(n);

        // Fill array with random numbers
        generate(arr.begin(), arr.end(), rand);

        auto start = high_resolution_clock::now(); // Start time
        quickSort(arr, 0, n - 1);
        auto end = high_resolution_clock::now();   // End time

        long long duration = duration_cast<nanoseconds>(end - start).count();

        // Compute complexity values
        double n_log_n = n * log2(n);
        double n_squared = pow(n, 2);

        // Store data in CSV
        file << n << "," << duration << "," << n_log_n << "," << n_squared << "\n";
        cout << "n = " << n << ", Time = " << duration << " ns\n";
    }

    file.close();
    cout << "Data saved to quicksort_runtime.csv\n";
    return 0;
}
