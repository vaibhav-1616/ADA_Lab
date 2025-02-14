#include <iostream>
#include <cstdlib>
#include <ctime>
#include<vector>
#include<chrono>
#include<fstream>

using namespace std;
using namespace std::chrono;


struct Activity {
    int start, finish;
};

vector<Activity> generateActivities(int count, int max_range){
    vector<Activity>activities;

    srand(time(0));

    for(int i=0; i<count; i++){
        int start = rand() % max_range;
        int finish = start + (rand()% (max_range - start));

        activities.push_back({start, finish});
    }
    return activities;
}

// mode = 0 -> sort by finish time, mode = 1 -> sort by start time.
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


// mode = 1 -> sort by start time
void activity_selection1(vector<Activity>&arr, int n){
    quickSort(arr, 0, n-1, 1);                      // mode = 1

    cout<<"Selected activities: "<<endl;

    cout<<"("<<arr[0].start<<", "<<arr[0].finish<<")"<<endl;

    int previous_activity_finish_time = arr[0].finish;
    int count = 1;                                      // coz first activity already included

    for(int i=1; i<n; i++){
        if(arr[i].start>=previous_activity_finish_time){
            cout<<"("<<arr[i].start<<", "<<arr[i].finish<<")"<<endl;
            previous_activity_finish_time = arr[i].finish;
            count++;
        }
    }

    cout<<"Maximum activities executed (sorted by start time): "<<count<<endl;
}


// mode = 0 -> sort by finish time
void activity_selection0(vector<Activity>&arr, int n){
    quickSort(arr, 0, n-1, 0);                      // mode = 0

    cout<<"Selected activities: "<<endl;

    cout<<"("<<arr[0].start<<", "<<arr[0].finish<<")"<<endl;

    int previous_activity_finish_time = arr[0].finish;
    int count = 1;                                      // coz first activity already included

    for(int i=1; i<n; i++){
        if(arr[i].start>=previous_activity_finish_time){
            cout<<"("<<arr[i].start<<", "<<arr[i].finish<<")"<<endl;
            previous_activity_finish_time = arr[i].finish;
            count++;
        }
    }

    cout<<"Maximum activities executed (sorted by finish time): "<<count<<endl;
}

int main() {

    // Activity arr[] = {{1, 3}, {2, 5}, {3, 9}, {6, 8}, {5, 7}, {8, 9}};
    // int n = sizeof(arr) / sizeof(arr[0]);

    // int mode = 1;           // sort by start time

    // quickSort(arr, 0, n-1, mode);

    // cout << "Sorted by " << ((mode == 0) ? "finish time" : " start time") << ":\n";
    // for (int i = 0; i < n; i++) {
    //     cout << "{" << arr[i].start << "," << arr[i].finish << "}\n";
    // }
    // cout<<endl;

    // int num_of_activities = 100;
    // int max_range = 86400;

    // vector<Activity>activities = generateActivities(num_of_activities, max_range);
    // int n = activities.size();

    // for(auto&activity: activities){
    //     cout<<"("<<activity.start<<", "<<activity.finish<<")"<<endl;
    // }

    // cout<<"-----------------"<<endl;

    // auto start1 = high_resolution_clock::now(); 
    // activity_selection1(activities, n-1);
    // auto end1 = high_resolution_clock::now();   

    // long long duration1 = duration_cast<nanoseconds>(end1 - start1).count();


    
    // auto start0 = high_resolution_clock::now(); 
    // activity_selection0(activities, n-1);
    // auto end0 = high_resolution_clock::now();   

    // long long duration0 = duration_cast<nanoseconds>(end0 - start0).count();

    // cout<<"---------------------------------"<<endl;

    // cout<<duration0<<" nanoseconds"<<endl;
    // cout<<duration1<<" nanoseconds"<<endl;


    int max_range = 86400;

    ofstream file("execution_times.csv");
    file << "num_activities,time_sort_by_start,time_sort_by_finish\n"; // CSV header

    for (int num_of_activities = 10; num_of_activities <= 1000; num_of_activities += 10) { // Vary size
        vector<Activity> activities = generateActivities(num_of_activities, max_range);
        int n = activities.size();

        auto start1 = high_resolution_clock::now(); 
        activity_selection1(activities, n - 1);
        auto end1 = high_resolution_clock::now();   
        long long duration1 = duration_cast<nanoseconds>(end1 - start1).count(); // Convert to ms

        auto start0 = high_resolution_clock::now(); 
        activity_selection0(activities, n - 1);
        auto end0 = high_resolution_clock::now();   
        long long duration0 = duration_cast<nanoseconds>(end0 - start0).count();

        // Write data to CSV file
        file << num_of_activities << "," << duration1 << "," << duration0 << "\n";

        // cout << "Activities: " << num_of_activities << " | Time (Start Sort): " << duration1 
        //      << " ns | Time (Finish Sort): " << duration0 << " ns\n";
    }

    file.close();


    return 0;
}
