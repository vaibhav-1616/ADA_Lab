#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;
using namespace std::chrono;

// Function to perform selection sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
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

        // Measure the time taken for selection sort
        auto start = high_resolution_clock::now();
        selectionSort(arr);
        auto stop = high_resolution_clock::now();

        // Calculate the duration
        auto duration = duration_cast<milliseconds>(stop - start);

        // Print the size of the array and the time taken
        cout << n << "\t" << duration.count() << endl;
    }

    return 0;
}