#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

int partition(vector<int> &arr, int l, int h) {
    int pivot = arr[l];
    int i = l + 1;
    int j = h;

    while (true) {
        while (i <= j && arr[i] < pivot) i++;
        while (j >= l && arr[j] > pivot) j--;

        if (i >= j) break;
        swap(arr[i], arr[j]);
    }

    swap(arr[l], arr[j]);
    return j;
}

// QuickSort Function
void quicksort(vector<int> &arr, int l, int h) {
    if (l >= h) return;
    int p = partition(arr, l, h);
    quicksort(arr, l, p - 1);
    quicksort(arr, p + 1, h);
}

int main() {
    srand(time(0));

    for (int n = 100000; n <= 1000000; n += 100000) { 
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 900001 + 100000;
        }

        cout << "Sorting for n = " << n << "...\n"; // Debugging Progress

        auto start = high_resolution_clock::now();
        quicksort(arr, 0, n - 1);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(stop - start);
        cout << "Time taken by QuickSort for n = " << n << ": " << duration.count() << " nanoseconds\n";
    }

    cout << "Sorting completed successfully!\n";
    return 0;
}
