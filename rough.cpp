#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // Seed for random number generation

    int rows = 5;
    int cols = 2;
    vector<vector<int>> randomNumbers(rows, vector<int>(cols));

    // Fill the 2D vector with random numbers between 10 and 100
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            randomNumbers[i][j] = 10 + rand() % 90; // Generates numbers between 10 and 100
        }
    }

    // Print the generated random numbers
    for (const auto& row : randomNumbers) {
        for (int num : row) {
            cout << num << "\t";
        }
        cout << endl;
    }

    return 0;
}