#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Item {
    int weight;
    int profit;
};

void bubbleSortByProfit(vector<Item>& items) {                      // by profit    
    int n = items.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (items[j].profit < items[j + 1].profit) {  
                swap(items[j], items[j + 1]);
            }
        }
    }
}

void bubbleSortByWeight(vector<Item>& items) {                      // by weight    
    int n = items.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (items[j].weight > items[j + 1].weight) {  
                swap(items[j], items[j + 1]);
            }
        }
    }
}

void bubbleSortByProfitPerWeight(vector<Item>& items) {                      // profit/weight    
    int n = items.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if ((items[j].profit / (float)items[j].weight) < (items[j + 1].profit / (float)items[j + 1].weight)) {  
                swap(items[j], items[j + 1]);
            }
        }
    }
}

float knapsack(int capacity, vector<Item>& items, vector<float>& fractions) {
    bubbleSortByWeight(items);

    float totalprofit = 0.0;
    int totalweight = 0;
    fractions.resize(items.size(), 0.0);

    for (size_t i = 0; i < items.size(); i++) {
        if (items[i].weight + totalweight <= capacity) {
            totalweight += items[i].weight;
            totalprofit += items[i].profit;
            fractions[i] = 1.0;
        } else {
            float fraction = (float)(capacity - totalweight) / items[i].weight;
            totalprofit += items[i].profit * fraction;
            fractions[i] = fraction;
            break;
        }
    }

    return totalprofit;
}

int main() {
    int capacity = 500;

    srand(time(0)); // Seed for random number generation

    int numItems = 10;
    vector<Item> items(numItems);

    // Measure time for generating random numbers
    auto start = high_resolution_clock::now();
    // Fill the vector with random numbers between 10 and 100
    for (int i = 0; i < numItems; i++) {
        items[i].weight = 10 + rand() % 91; // Generates weights between 10 and 100
        items[i].profit = 10 + rand() % 91; // Generates profits between 10 and 100
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken to generate random numbers: " << duration.count() << " milliseconds" << endl;

    // Print the generated random numbers
    cout << "Generated Items:" << endl;
    for (const auto& item : items) {
        cout << "Weight: " << item.weight << ", Profit: " << item.profit << endl;
    }
    cout << endl;

    vector<Item> itemsCopy = items;

    // Measure time for sorting by profit
    start = high_resolution_clock::now();
    bubbleSortByProfit(itemsCopy);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken to sort by profit: " << duration.count() << " milliseconds" << endl;

    // Print sorted items by profit
    cout << "Sorted Items by Profit:" << endl;
    for (const auto& item : itemsCopy) {
        cout << "Weight: " << item.weight << ", Profit: " << item.profit << endl;
    }
    cout << endl;

    itemsCopy = items;

    // Measure time for sorting by weight
    start = high_resolution_clock::now();
    bubbleSortByWeight(itemsCopy);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken to sort by weight: " << duration.count() << " milliseconds" << endl;

    // Print sorted items by weight
    cout << "Sorted Items by Weight:" << endl;
    for (const auto& item : itemsCopy) {
        cout << "Weight: " << item.weight << ", Profit: " << item.profit << endl;
    }
    cout << endl;

    itemsCopy = items;

    // Measure time for sorting by profit/weight ratio
    start = high_resolution_clock::now();
    bubbleSortByProfitPerWeight(itemsCopy);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken to sort by profit/weight ratio: " << duration.count() << " milliseconds" << endl;

    // Print sorted items by profit/weight ratio
    cout << "Sorted Items by Profit/Weight Ratio:" << endl;
    for (const auto& item : itemsCopy) {
        cout << "Weight: " << item.weight << ", Profit: " << item.profit << endl;
    }
    cout << endl;

    vector<float> fractions;
    float totalprofit = knapsack(capacity, items, fractions);
    cout << endl;

    cout << "Total Profit: " << totalprofit << endl;
    cout << "Fractions: ";
    for (float fraction : fractions) {
        cout << fraction << " ";
    }
    cout << endl;

    for (int i = 0; i < 10; i++) {
        cout << items[i].weight << " ";
    }

    return 0;
}