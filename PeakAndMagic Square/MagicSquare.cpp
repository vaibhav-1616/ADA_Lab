#include <iostream>
#include <vector>
using namespace std;

// Function to generate an odd-order magic square
void generateMagicSquare(int n) {
    vector<vector<int>> magicSquare(n, vector<int>(n, 0));

    // Initialize position for 1
    int i = 0;
    int j = n / 2;

    // One by one put all values in magic square
    for (int num = 1; num <= n * n; ) {
        // Condition 4: If the calculated position is out of bounds
        if (i < 0 && j == n) {
            i = 0;
            j = n - 1;
        } else {
            // Wrap around the row
            if (i < 0) {
                i = n - 1;
            }
            // Wrap around the column
            if (j == n) {
                j = 0;
            }
        }

        // Condition 2: If the cell is already occupied
        if (magicSquare[i][j] != 0) {
            i += 2;
            j--;
            continue;
        } else {
            // Add num to cell
            magicSquare[i][j] = num++;
        }

        // Move to next position
        i--;
        j++;
    }

    // Print the magic square
    cout << "The Magic Square for n=" << n << ":\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << magicSquare[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Sum of each row or column: " << n * (n * n + 1) / 2 << endl;
}

int main() {
    int n;
    cout << "Enter the size of the magic square (odd number): ";
    cin >> n;

    if (n % 2 == 0) {
        cout << "Magic square is not possible for even numbers." << endl;
    } else {
        generateMagicSquare(n);
    }

    return 0;
}