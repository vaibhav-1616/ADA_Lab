#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Item {
    int weight;
    int profit;
};

void bubbleSortByProfitPerWeight(vector<Item>& items) {                      // profit/weight    
    int n = items.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if ((items[j].profit / (float)items[j].weight )< (items[j + 1].profit / (float)items[j+1].weight)) {  
                swap(items[j], items[j + 1]);
            }
        }
    }
}

float knapsack(int capacity, vector<Item>& items, vector<float>& fractions) {
    bubbleSortByProfitPerWeight(items);

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

    // Fill the vector with random numbers between 10 and 100
    for (int i = 0; i < numItems; i++) {
        items[i].weight = 10 + rand() % 91; // Generates weights between 10 and 100
        items[i].profit = 10 + rand() % 91; // Generates profits between 10 and 100
    }

    cout<<"Original: "<<endl;
    for (const auto& item : items) {
        cout << "Weight: " << item.weight << ", Profit: " << item.profit << endl;
    }

    bubbleSortByProfitPerWeight(items);

    cout<<"------------------"<<endl;
    cout<<"After sorting: "<<endl;

    for (const auto& item : items) {
        cout << "Weight: " << item.weight << ", Profit: " << item.profit << endl;
    }

    vector<float> fractions;
    float totalprofit = knapsack(capacity, items, fractions);
    cout<<endl;

    cout << "Total Profit: " << totalprofit << endl;
    cout << "Fractions: ";
    for (float fraction : fractions) {
        cout << fraction << " ";
    }
    cout << endl;

    for(int i=0; i<10; i++){
        cout<<items[i].weight<<" ";
    }

    return 0;
}