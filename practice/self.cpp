#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

int partition(vector<int>& arr, int l, int h){
    int pivot = arr[l];
    int i = l+1; 
    int j = h;

    while(true){
        while(i<=j && arr[i]<=pivot){
            i++;
        }

        while(i<=j && arr[j]>pivot){
            j--;
        }

        if(i>=j) break;
        else{
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[l], arr[j]);

    return j;

}

void quicksort(vector<int> &arr, int l, int h){
    if(l<h){
        int p = partition(arr, l, h);
        quicksort(arr, l, p-1);
        quicksort(arr, p+1, h);
    }
}

int main() {

    // vector<int> arr = {10, 7, 8, 9, 1, 5, 4, 9, 13, 2};
    // int n = arr.size();

    // quicksort(arr, 0, n-1);

    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }

    srand(time(0));

    for(int n=10000; n<=100000; n+=10000){
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            arr[i] = rand() % 90001 + 10000;
        }

        cout << "Sorting for n = " << n << "...\n";

        auto start = high_resolution_clock::now();
        quicksort(arr, 0, n-1);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        cout << "Time taken by QuickSort for n = " << n << ": " << duration.count() << " microseconds\n";
    }


    return 0;
}
