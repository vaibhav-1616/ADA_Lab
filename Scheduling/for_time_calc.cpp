#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

struct Activity {
    int start, finish;
};

vector<Activity> generateActivities(int count, int max_range) {
    vector<Activity> activities;
    srand(time(0));

    for (int i = 0; i < count; i++) {
        int start = rand() % max_range;
        int finish = start + (rand() % (max_range - start));
        activities.push_back({start, finish});
    }
    return activities;
}

// QuickSort functions (same as before)...

int partition(vector<Activity>&arr, int low, int high, int mode) {
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

void quickSort(vector<Activity>&arr, int low, int high, int mode) {
    if (low >= high) return; // Base case

    int pivotIndex = partition(arr, low, high, mode);
    quickSort(arr, low, pivotIndex - 1, mode);
    quickSort(arr, pivotIndex + 1, high, mode);
}

void activity_selection1(vector<Activity>& arr, int n) {
    quickSort(arr, 0, n - 1, 1); // Sort by start time
}

void activity_selection0(vector<Activity>& arr, int n) {
    quickSort(arr, 0, n - 1, 0); // Sort by finish time
}

int main() {
    int max_range = 86400;
    
    ofstream file("sort_times.csv");
    file << "num_activities,time_sort_by_start,time_sort_by_finish\n"; // CSV header

    for (int num_of_activities = 100000; num_of_activities <= 1000000; num_of_activities += 100000) { 
        vector<Activity> activities = generateActivities(num_of_activities, max_range);
        int n = activities.size();

        auto start1 = high_resolution_clock::now();
        activity_selection1(activities, n - 1);
        auto end1 = high_resolution_clock::now();
        long long duration1 = duration_cast<nanoseconds>(end1 - start1).count();

        auto start0 = high_resolution_clock::now();
        activity_selection0(activities, n - 1);
        auto end0 = high_resolution_clock::now();
        long long duration0 = duration_cast<nanoseconds>(end0 - start0).count();

        // Write results to CSV file
        file << num_of_activities << "," << duration1 << "," << duration0 << "\n";

        // cout << "Activities: " << num_of_activities 
        //      << " | Sort by Start Time: " << duration1 << " ms"
        //      << " | Sort by Finish Time: " << duration0 << " ms\n";
    }

    file.close();
    return 0;
}
