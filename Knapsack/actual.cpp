#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int profit;
};


bool sort_by_ratio(const Item &a, const Item &b) {
    return (double)a.profit / a.weight > (double)b.profit / b.weight; // Sort in descending order
}

void fractionalKnapsack(vector<Item> &items, int capacity) {
    // Sort items by profit/weight ratio
    sort(items.begin(), items.end(), sort_by_ratio);

    vector<double> flag(items.size(), 0.0); 

    double totalProfit = 0.0;
    int currentWeight = 0;          // ab tak kitna weight ham fill kr chuke hai in the knapsack

    for (int i = 0; i < items.size(); i++) {
        if (currentWeight + items[i].weight <= capacity) {
            // Include the whole item
            totalProfit += items[i].profit;
            currentWeight += items[i].weight;
            flag[i] = 1.0;
        } else {
            // Include fraction of the item
            double fraction = (double)(capacity - currentWeight) / items[i].weight;
            totalProfit += items[i].profit * fraction;
            flag[i] = fraction;
            break; // Knapsack is full
        }
    }

    cout<<"Items: ";
    for(int i=0; i<items.size(); i++){
        cout<<"("<<items[i].weight<<", "<<items[i].profit<<")"<<"\t";
    }

    cout<<endl;
    
    cout<<"Flag: ";
    for(int i=0; i<items.size(); i++){
        cout<<flag[i]<<" \t \t";
    }
    cout<<endl;

    cout << "Total profit in knapsack = " << totalProfit << endl;
}

int main() {
    
    vector<Item> items = {
        {10, 100},
        {20, 120},
        {30, 140},
        {40, 150},
        {50, 200}
    };
    
    int capacity = 100;

    fractionalKnapsack(items, capacity);

    return 0;
}
