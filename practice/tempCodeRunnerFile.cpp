#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Improved Partition function with first element as pivot
int partition(vector<int> &arr, int l, int h) {
    int pivot = arr[l];  // First element as pivot
    int i = l + 1;
    int j = h;

    while (true) {
        // Move i forward if arr[i] is smaller than pivot
        while (i<=j && arr[i] <= pivot) i++;
        // Move j backward if arr[j] is greater than pivot
        while (j>=i && arr[j] > pivot) j--;

        // If pointers cross, break
        if (i >= j) break;
        swap(arr[i], arr[j]); // Swap elements to ensure correct partition
    }

    swap(arr[l], arr[j]); // Place pivot at its correct position
    return j;  // Return final pivot position
}


// QuickSort Function
void quicksort(vector<int> &arr, int l, int h) {
    if (l < h) {
        int p = partition(arr, l, h);
        quicksort(arr, l, p - 1);
        quicksort(arr, p + 1, h);
    }
}

int main() {
    srand(time(0));

    for (int n = 10000; n <= 100000; n += 10000) { 
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 90001 + 10000; // Generate random numbers between 1000 and 10000
        }

        cout << "Sorting for n = " << n << "...\n";
        // cout.flush(); // Ensure output is printed immediately

        auto start = high_resolution_clock::now();
        quicksort(arr, 0, n - 1);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken by QuickSort for n = " << n << ": " << duration.count() << " microseconds\n";
    }

    cout << "Sorting completed successfully!\n";
    return 0;
}
