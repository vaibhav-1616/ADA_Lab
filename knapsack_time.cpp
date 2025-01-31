#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Item {
    float profit;
    float weight;
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

void bubbleSortByWeight(vector<Item>& items) {
    int n = items.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (items[j].weight > items[j + 1].weight) {
                swap(items[j], items[j + 1]);
            }
        }
    }
}

void bubbleSortByProfitWeightRatio(vector<Item>& items) {
    int n = items.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if ((items[j].profit / items[j].weight) < (items[j + 1].profit / items[j + 1].weight)) {
                swap(items[j], items[j + 1]);
            }
        }
    }
}

void measureSortTime(void (*sortFunc)(vector<Item>&), vector<Item>& items, const string& sortName) {
    auto start = high_resolution_clock::now();
    sortFunc(items);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by " << sortName << ": " << duration.count() << " microseconds" << endl;
}

int main() {
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    vector<Item> itemsCopy;

    itemsCopy = items;
    measureSortTime(bubbleSortByProfit, itemsCopy, "bubbleSortByProfit");

    itemsCopy = items;
    measureSortTime(bubbleSortByWeight, itemsCopy, "bubbleSortByWeight");

    itemsCopy = items;
    measureSortTime(bubbleSortByProfitWeightRatio, itemsCopy, "bubbleSortByProfitWeightRatio");

    return 0;
}