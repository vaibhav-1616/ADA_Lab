#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <fstream>  

using namespace std;


#define MAX_LOAD 100  // Max capacity of the knapsack
#define profit_min 10
#define profit_range 90
#define weigth_min 10
#define weight_range 90
#define COL 4  // Number of columns in the item array

int partition(float items[][COL], int low, int high, int mode) {
    float pivot = 0;
    if (mode == 0) { // Sorting by profit
        pivot = items[high][0];
    } else if (mode == 1) { // Sorting by weight
        pivot = items[high][1];
    } else { // Sorting by profit/weight ratio
        pivot = items[high][0] / items[high][1];
    }

    int i = low - 1;

    for (int j = low; j < high; j++) {
        float value_j = 0;
        if (mode == 0) {
            value_j = items[j][0]; // profit
        } else if (mode == 1) {
            value_j = items[j][1]; // weight
        } else {
            value_j = items[j][0] / items[j][1]; // profit-to-weight ratio
        }

        if (value_j > pivot) {
            i++;
            swap(items[i], items[j]);
        }
    }
    swap(items[i + 1], items[high]);
    return i + 1;
}

// QuickSort function
void quickSort(float items[][COL], int low, int high, int mode) {
    if (low < high) {
        int pi = partition(items, low, high, mode);
        quickSort(items, low, pi - 1, mode);
        quickSort(items, pi + 1, high, mode);
    }
}

// Function to calculate the maximum profit using Fractional Knapsack
float fractionalKnapsack(int capacity, float items[][COL], int n) {
    float totalProfit = 0.0;
    int curr_load = 0;
    float per = 0;
    
    // Fill knapsack
    for (int i = n - 1; i >= 0; --i) {
        if (items[i][1] <= MAX_LOAD - curr_load) {
            curr_load += items[i][1];
            totalProfit += items[i][0]; // Full profit
        } else {
            per = (float)(MAX_LOAD - curr_load) / items[i][1];
            curr_load += items[i][1] * per;
            totalProfit += items[i][0] * per; // Fractional profit
        }
        if (curr_load == MAX_LOAD) {
            break;
        }
    }
    return totalProfit;
}

int main() {
    // Open file to write the output to a CSV file
    ofstream outputFile("knapsack_quickSort_runtime.csv");
    
    // Write the header to the CSV file
    outputFile << "size,time\n";

    // Loop over input sizes from 1000 to 100000 with increments of 1000
    for (int n = 1000; n <= 100000; n += 1000) {
        double res = 0;

        // Repeat the process 10 times to get an average
        for (int m = 0; m < 10; m++) {
            float items[n][COL];  // Array to store n items with 4 columns

            // Generate random items with profit and weight
            srand(time(NULL));
            for (int i = 0; i < n; ++i) {
                items[i][0] = rand() % profit_range + profit_min;   // Profit
                items[i][1] = rand() % weight_range + weigth_min;   // Weight
                items[i][2] = items[i][0] / items[i][1];             // Profit/Weight ratio
                items[i][3] = i + 1;                                 // Index (or another value)
            }

            // Measure time for sorting by profit (mode 0)
            auto start = chrono::high_resolution_clock::now();
            quickSort(items, 0, n - 1, 0);  // Sort by profit
            fractionalKnapsack(MAX_LOAD, items, n);  // Solve the knapsack for sorted items by profit
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            res += duration.count();  // Add the time taken for this run

            // Measure time for sorting by weight (mode 1)
            start = chrono::high_resolution_clock::now();
            quickSort(items, 0, n - 1, 1);  // Sort by weight
            fractionalKnapsack(MAX_LOAD, items, n);
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            res += duration.count();

            // Measure time for sorting by profit/weight ratio (mode 2)
            start = chrono::high_resolution_clock::now();
            quickSort(items, 0, n - 1, 2);  // Sort by profit-to-weight ratio
            fractionalKnapsack(MAX_LOAD, items, n);
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            res += duration.count();
        }

        // Output the average time for the current input size to the file
        outputFile << n << "," << fixed << res / 30 << "\n";  // Divided by 30 since we ran the test 3 times for 10 iterations
    }

    // Close the file after writing
    outputFile.close();

    return 0;
}
