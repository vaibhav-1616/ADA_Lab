#include <iostream>
using namespace std;

struct Activity {
    int start, finish;
};

// mode = 0 -> sort by finish time, mode = 1 -> sort by start time.
int partition(Activity arr[], int low, int high, int mode) {
    int pivot = (mode == 0) ? arr[low].finish : arr[low].start; 
    int i = low + 1, j = high;

    while (true) {
        while (i <= j && ((mode == 0) ? arr[i].finish : arr[i].start) <= pivot) i++; 
        while (j >= low && ((mode == 0) ? arr[j].finish : arr[j].start) > pivot) j--; 

        if (i >= j) break; 
        swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]); 
    return j; 
}

void quickSort(Activity arr[], int low, int high, int mode) {
    if (low >= high) return; // Base case

    int pivotIndex = partition(arr, low, high, mode);
    quickSort(arr, low, pivotIndex - 1, mode);
    quickSort(arr, pivotIndex + 1, high, mode);
}

int main() {
    Activity arr[] = {{1, 3}, {2, 5}, {3, 9}, {6, 8}, {5, 7}, {8, 9}};
    int n = sizeof(arr) / sizeof(arr[0]);

    int mode = 1; 

    quickSort(arr, 0, n-1, mode);

    cout << "Sorted by " << ((mode == 0) ? "finish time" : " start time") << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "{" << arr[i].start << "," << arr[i].finish << "}\n";
    }

    return 0;
}
