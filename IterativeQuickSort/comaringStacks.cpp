#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

// Partition function for QuickSort
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[high], arr[i + 1]);
    return i + 1;
}

// Recursive QuickSort with stack depth tracking
int Recursivequicksort(vector<int> &arr, int low, int high, int depth, int &maxDepth) {
    if (low < high) {
        if (depth > maxDepth) {
            maxDepth = depth;  // Update max recursive depth
        }
        int p = partition(arr, low, high);
        Recursivequicksort(arr, low, p - 1, depth + 1, maxDepth);
        Recursivequicksort(arr, p + 1, high, depth + 1, maxDepth);
    }
    return maxDepth;
}

// Iterative QuickSort with stack depth tracking
int Iterativequicksort(vector<int> &arr, int low, int high) {
    stack<int> s;
    int maxStack = 0; // Track max stack depth

    s.push(low);
    s.push(high);

    while (!s.empty()) {
        if (s.size() > maxStack) { 
            maxStack = s.size();  // Update max stack depth
        }

        high = s.top();
        s.pop();
        low = s.top();
        s.pop();

        if (low < high) {
            int p = partition(arr, low, high);

            // Push left partition
            s.push(low);
            s.push(p - 1);

            // Push right partition
            s.push(p + 1);
            s.push(high);
        }
    }
    return maxStack / 2;  // Since we push two elements per partition
}

int main() {
    srand(time(NULL));
    ofstream file("quicksort_stack_analysis.csv");

    file << "Size,Recursive_Stack,Iterative_Stack\n";
    cout << "Size,Recursive_Stack,Iterative_Stack\n";

    for (int n = 100000; n <= 1000000; n += 100000) {
        vector<int> a(n, 0), b(n, 0);
        for (int j = 0; j < n; ++j) {
            a[j] = b[j] = rand();
        }

        // Measure Recursive QuickSort stack depth
        int maxDepth = 0;
        Recursivequicksort(a, 0, n - 1, 1, maxDepth);

        // Measure Iterative QuickSort stack depth
        int maxStack = Iterativequicksort(b, 0, n - 1);

        cout << n << "," << maxDepth << "," << maxStack << "\n";
        file << n << "," << maxDepth << "," << maxStack << "\n";
    }

    file.close();
    cout << "Results saved to quicksort_stack_analysis.csv\n";
    return 0;
}
