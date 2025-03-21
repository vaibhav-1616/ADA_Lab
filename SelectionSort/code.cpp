#include <iostream>
#include <vector>
#include <chrono>
#include <fstream> // Include for file handling
#include <cstdlib>

using namespace std;
using namespace std::chrono;

void selectionSort(vector<int> &arr)
{
    int size = arr.size();

    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main()
{
    ofstream file("selection_sort_times.csv"); // Open file for writing
    file << "Size,Time\n"; // Write CSV headers

    srand(time(0));

    for(int n=10000; n<=100000; n+=10000){
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            arr[i] = rand() % 90001 + 10000;
        }

        cout << "Sorting for n = " << n << "...\n";

        auto start = high_resolution_clock::now();
        selectionSort(arr);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<seconds>(stop - start);

        cout << "Time taken by Selection Sort for n = " << n << ": " << duration.count() << " seconds\n";

        file << n << "," << duration.count() << "\n"; 
    }


    file.close();
    cout << "Data saved to selection_sort_times.csv\n";

    return 0;
}
