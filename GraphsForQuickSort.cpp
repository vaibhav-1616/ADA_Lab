#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;
using namespace std::chrono;

// Function to partition the array
int partition(vector<int>& arr, int low, int high) {
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

// Function to perform quicksort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    srand(time(0)); // Seed for random number generation

    cout << "n\tTime (milliseconds)" << endl;

    for (int n = 1000; n <= 10000; n += 1000) {
        vector<int> arr(n);

        // Fill the array with random numbers
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 10000;
        }

        // Measure the time taken for quicksort
        auto start = high_resolution_clock::now();
        quickSort(arr, 0, n - 1);
        auto stop = high_resolution_clock::now();

        // Calculate the duration
        auto duration = duration_cast<milliseconds>(stop - start);

        // Print the size of the array and the time taken
        cout << n << "\t" << duration.count() << endl;
    }

    return 0;
}