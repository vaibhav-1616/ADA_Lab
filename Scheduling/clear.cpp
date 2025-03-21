#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to store activity details
struct Activity {
    int id, start, finish;
};

// Comparator function to sort activities by finish time
bool compareByFinish(Activity a, Activity b) {
    return a.finish < b.finish;
}

// Function to perform Activity Selection
void activitySelection(vector<Activity> &activities) {
    cout << "\nSelected Activities (Sorted by Finish Time):\n";

    // Sort activities by finish time
    sort(activities.begin(), activities.end(), compareByFinish);

    int lastFinishTime = 0;
    for (auto act : activities) {
        if (act.start >= lastFinishTime) {
            cout << "Activity " << act.id << " (Start: " << act.start << ", Finish: " << act.finish << ")\n";
            lastFinishTime = act.finish;
        }
    }
}

int main() {
    // 8 predefined activities
    vector<Activity> activities = {
        {1, 1, 3}, {2, 2, 5}, {3, 4, 6}, {4, 6, 8},
        {5, 5, 7}, {6, 8, 9}, {7, 3, 9}, {8, 7, 10}
    };

    // Sorting and displaying by finish time
    cout << "Activities sorted by Finish Time:\n";
    sort(activities.begin(), activities.end(), compareByFinish);
    for (auto act : activities) {
        cout << "Activity " << act.id << " ( " << act.start << ", " << act.finish << ")\n";
    }

    // Perform Activity Selection
    activitySelection(activities);

    return 0;
}
