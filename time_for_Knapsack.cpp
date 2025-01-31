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

void bubbleSortByProfit(vector<Item>& items) {
    int n = items.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (items[j].profit < items[j + 1].profit) {
                swap(items[j], items[j + 1]);
            }
        }
    }
}

// void bubbleSortByWeight(vector<Item>& items) {
//     int n = items.size();
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = 0; j < n - 1 - i; j++) {
//             if (items[j].weight > items[j + 1].weight) {
//                 swap(items[j], items[j + 1]);
//             }
//         }
//     }
// }

// void bubbleSortByProfitWeightRatio(vector<Item>& items) {
//     int n = items.size();
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = 0; j < n - 1 - i; j++) {
//             if ((items[j].profit / (float)items[j].weight) < (items[j + 1].profit / (float)items[j + 1].weight)) {
//                 swap(items[j], items[j + 1]);
//             }
//         }
//     }
// }

float knapsack(int capacity, vector<Item>& items, vector<float>& fractions) {
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

void measureSortTime(void (*sortFunc)(vector<Item>&), vector<Item>& items, const string& sortName) {
    auto start = high_resolution_clock::now();
    sortFunc(items);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Sort Method: " << sortName << endl;
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;
    cout << "Sorted Items:" << endl;
    for (const auto& item : items) {
        cout << "Weight: " << item.weight << ", Profit: " << item.profit << endl;
    }
    cout << endl;
}

int main() {
    int capacity = 500;

    srand(time(0)); // Seed for random number generation

    int numItems = 20; // Increase the number of items
    vector<Item> items(numItems);

    // Fill the vector with random numbers between 10 and 100
    for (int i = 0; i < numItems; i++) {
        items[i].weight = 10 + rand() % 91; // Generates weights between 10 and 100
        items[i].profit = 10 + rand() % 91; // Generates profits between 10 and 100
    }

    // Print the generated random numbers
    cout << "Generated Items:" << endl;
    for (const auto& item : items) {
        cout << "Weight: " << item.weight << ", Profit: " << item.profit << endl;
    }
    cout << endl;

    vector<Item> itemsCopy = items;

    // measureSortTime(bubbleSortByProfit, itemsCopy, "Bubble Sort by Profit");
    auto start = high_resolution_clock::now();
    bubbleSortByProfit(itemsCopy);
    auto stop = high_resolution_clock::now();

    // Calculate the duration
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time: " << "\t" << duration.count() << endl;

    // itemsCopy = items;
    // measureSortTime(bubbleSortByWeight, itemsCopy, "Bubble Sort by Weight");

    // itemsCopy = items;
    // measureSortTime(bubbleSortByProfitWeightRatio, itemsCopy, "Bubble Sort by Profit/Weight Ratio");

    vector<float> fractions;
    float totalprofit = knapsack(capacity, items, fractions);

    cout << "Total Profit: " << totalprofit << endl;
    cout << "Fractions: ";
    for (float fraction : fractions) {
        cout << fraction << " ";
    }
    cout << endl;

    return 0;
}