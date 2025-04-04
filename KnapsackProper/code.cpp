#include <iostream>
#include<vector>
#include<set>

using namespace std;

// merge and purge functions

// merge function adds new state i.e. a new {weight, value} pair to the existing set whenever a new item {wi, vi} is considered...

set<pair<int, int>> merge(set<pair<int, int>> &states, int wi, int vi, int W) {
    set<pair<int, int>> newStates = states;  // Copy current states

    // wi is the weight of the current item being considered in the knapsack problem.
    // newWeight -> the total weight that we get after adding the current item to already existng items in the "states"...
    // [it.first]represents the weight of an existing state.


    for (auto it : states) {
        int newWeight = it.first + wi;          
        int newValue = it.second + vi;

        if (newWeight <= W) {
            newStates.insert({newWeight, newValue});
        }
    }

    return newStates;
}

// After merging new weight-value pairs, some states might be dominated by others. The purge function removes these dominated states to keep only the most optimal ones.

// A state (w, v) is dominated if: There exists another state (w', v') where: w' ≤ w (same or lower weight) v' ≥ v (same or higher value)
// If (4, 20) exists, but (3, 25) also exists → Remove (4,20) because (3,25) is strictly better.


set<pair<int, int>> purge(set<pair<int, int>> &states) {
    set<pair<int, int>> purifiedStates;
    pair<int, int> best = {-1, -1}; // (weight, value)

    for (auto it : states) {
        int w = it.first;
        int v = it.second;

        // If the new state has better value than previous best, keep it
        if (best.second < v) {
            best = {w, v};
            purifiedStates.insert(best);
        }
    }

    return purifiedStates;
}


void printStates(const set<pair<int, int>> &states) {
    cout << "Final states (Weight, Value):\n";
    for (auto it : states) {
        cout << "(" << it.first << ", " << it.second << ") ";
    }
    cout << endl;
}


int knapsack(int W, vector<int> &weights, vector<int> &values) {
    set<pair<int, int>> states = {{0, 0}}; // Initial state (0 weight, 0 value)

    int n = weights.size();
    for (int i = 0; i < n; i++) {
        states = merge(states, weights[i], values[i], W); // Merge new item
        states = purge(states); // Purge dominated states
    }

    printStates(states);

    // Find the maximum value within weight limit W
    int maxValue = 0;
    for (auto it : states) {
        if (it.first <= W) {
            maxValue = max(maxValue, it.second);
        }
    }

    return maxValue;
}


int main() {

    int W = 6;  
    vector<int> weights = {2, 3, 4};  
    vector<int> values = {10, 15, 20};  

    int maxProfit = knapsack(W, weights, values);
    cout << "Maximum Profit: " << maxProfit << endl;
    
    return 0;
}