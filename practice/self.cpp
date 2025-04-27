#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include<stack>

using namespace std;
using namespace std::chrono;

// int partition(vector<int>& arr, int l, int h){
//     int pivot = arr[l];
//     int i = l+1;
//     int j = h;

//     while(true){
//         while(i<=j && arr[i]<=pivot){
//             i++;
//         }

//         while(i<=j && arr[j]>pivot){
//             j--;
//         }

//         if(i>=j) break;
//         else{
//             swap(arr[i], arr[j]);
//         }
//     }

//     swap(arr[l], arr[j]);

//     return j;

// }

// void quicksort(vector<int> &arr, int l, int h){
//     if(l<h){
//         int p = partition(arr, l, h);
//         quicksort(arr, l, p-1);
//         quicksort(arr, p+1, h);
//     }
// }

// int main() {

//     // vector<int> arr = {10, 7, 8, 9, 1, 5, 4, 9, 13, 2};
//     // int n = arr.size();

//     // quicksort(arr, 0, n-1);

//     // for(int i=0; i<n; i++){
//     //     cout<<arr[i]<<" ";
//     // }

//     srand(time(0));

//     for(int n=10000; n<=100000; n+=10000){
//         vector<int> arr(n);
//         for(int i=0; i<n; i++){
//             arr[i] = rand() % 90001 + 10000;
//         }

//         cout << "Sorting for n = " << n << "...\n";

//         auto start = high_resolution_clock::now();
//         quicksort(arr, 0, n-1);
//         auto stop = high_resolution_clock::now();

//         auto duration = duration_cast<microseconds>(stop - start);

//         cout << "Time taken by QuickSort for n = " << n << ": " << duration.count() << " microseconds\n";
//     }

//     return 0;
// }

// KNAPSACK

// struct item{
//     int weight;
//     int profit;
// };

// bool sort_by_pw(const item&a, const item&b){
//     return (double)a.profit/a.weight > (double)b.profit/b.weight;
// }

// void knapsack(vector<item> &items, int capacity){

//     sort(items.begin(), items.end(), sort_by_pw);       // descending order by p/w ratio

//     vector<double>flag(items.size(), 0.0);

//     float tp = 0.0;     // profit
//     int cw = 0;         // weight filled until now

//     for(int i=0; i<items.size(); i++){
//         if(cw + items[i].weight <= capacity){
//             tp += items[i].profit;
//             cw += items[i].weight;
//             flag[i] = 1.0;
//         }

//         else{           // this comes when we are at the last item that cannot be fully included
//             double fraction = (double)(capacity - cw) / items[i].weight;
//             // cw is not equal to the capacity
//             tp += items[i].profit * fraction;
//             flag[i] = fraction;
//             break;      // coz know the knapsack is full
//         }
//     }

//     cout<<"Items: ";
//     for(int i=0; i<items.size(); i++){
//         cout<<"("<<items[i].profit<<", "<<items[i].weight<<")"<<"\t";
//     }

//     cout<<endl;

//     cout<<"Flag: ";
//     for(int i=0; i<items.size(); i++){
//         cout<<flag[i]<<" \t \t";
//     }
//     cout<<endl;

//     cout<<"Total profit = "<<tp<<endl;

// }

// int main(){

//     vector<item> items = {
//         {10, 100},
//         {20, 120},
//         {30, 140},
//         {40, 150},
//         {50, 200}
//     };

//     int capacity = 100;

//     knapsack(items, capacity);

//     return 0;
// }

int op_peak(vector<int> arr, int low, int high)
{

    int mid = (low + high) / 2;
    int peak_ind = 0;

    if (arr[mid] >= arr[mid + 1] && arr[mid] >= arr[mid - 1])
    {
        peak_ind = mid;
    }

    else if (arr[mid] < arr[mid - 1])
    {
        return op_peak(arr, low, mid - 1);
    }
    else
    {
        return op_peak(arr, mid + 1, high);
    }

    return peak_ind;
}


int peak_2d(vector<vector<int>> arr, int low, int high){
    int mid = (low + high) / 2;

    int max_row_ind = 0;
    int rows = arr.size();
    int cols = arr[0].size();

    for(int i=1; i<rows; i++){
        if(arr[max_row_ind][mid] < arr[i][mid]){
            max_row_ind = i;
        }
    }

    // now we have the max element in the middle column along with the row number in which it is present

    if(arr[max_row_ind][mid] >= arr[max_row_ind][mid+1] && arr[max_row_ind][mid] >= arr[max_row_ind][mid-1]){
        return arr[max_row_ind][mid];
    }
    else if(arr[max_row_ind][mid] < arr[max_row_ind][mid+1]){
        return peak_2d(arr, mid+1, high);
    }
    else{
        return peak_2d(arr, low, mid-1);
    }
}


void magicSquare(int n){

    vector<vector<int>> magicSq(n, vector<int>(n, 0));
    
    int num = 1;

    int i = 0, j = n / 2;

    while(num<= n*n){
        magicSq[i][j] = num;
        num++;

        // we move up and then right (up-right) :D

        int new_i = (i-1 + n) % n;          // moving up
        int new_j = (j+1) % n;              // moving right

        if(magicSq[new_i][new_j] != 0){
            i = (i+1) % n;                  // if that place (up-right) is already occupied then just place the next number in the  immediate next row (just below)
        }
        else{
            i = new_i;
            j = new_j;
        }
    }

    for(auto &row : magicSq){
        for(int val: row){
            cout<<val<<" ";
        }
        cout<<endl;
    }

}


void selectionSort(vector<int> &arr){
    int size = arr.size();

    for(int i=0; i<size-1; i++){
        int min_index = i;

        for(int j=i+1; j<size; j++){
            if(arr[j]<arr[min_index]){
                min_index = j;
            }
        }

        if(min_index != i){
            swap(arr[i], arr[min_index]);
        }
    }
}

void print(vector<int>arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}


int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];

    int i = low + 1;
    int j = high;

    while(true){

        while(i<=j && arr[i]<= pivot){
            i++;
        }

        while(i<=j && arr[j]> pivot){
            j--;
        }

        if(i>j){
            break;
        }
        else{ 
        swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]);
    return j;
}



void iterative(vector<int> &arr, int low, int high){
    stack<int> s;

    s.push(low);
    s.push(high);

    while(!s.empty()){
        high = s.top();
        s.pop();

        low = s.top();
        s.pop();

        if(low<high){
            int p = partition(arr, low, high);

            s.push(low);            // left sub-array
            s.push(p-1);

            s.push(p+1);            // right sub-array
            s.push(high);

        }
    }
}

// void quick(vector<int> &arr, int low, int high){
//         if(low<high){
//             int p = partition(arr, low, high);
//             quick(arr, low, p-1);
//             quick(arr, p+1, high);
    
//         }
//     }



struct item{
    int weight;
    int profit;
};

bool sort_by_pw_ratio(item &a, item &b){
    return (double) a.profit / a.weight > (double) b.profit / b.weight;
}

void knapsack(vector<item> &items, int max_cap){

    sort(items.begin(), items.end(), sort_by_pw_ratio);

    vector<double> flag(items.size(), 0.0);

    float total_profit = 0.0;
    int curr_weight = 0;

    for(int i=0; i<items.size(); i++){
        if(curr_weight + items[i].weight <= max_cap){
            total_profit += items[i].profit;
            curr_weight += items[i].weight;
            flag[i] = 1.0;
        }

        else{
            double fraction = (double)(max_cap - curr_weight) / items[i].weight;
            total_profit += items[i].profit * fraction;
            flag[i] = fraction;
            break;      // coz now knapsack is full :D

        }
    }

    for(int i=0; i<items.size(); i++){
        cout<<items[i].weight<<" "<<items[i].profit<<endl;
    }

    cout<<"Flag array: ";

    for(int i=0; i<items.size(); i++){
        cout<<flag[i]<<" ";
    }
    cout<<endl;

    cout<<"Total profit = "<<total_profit<<endl;


}


int main()
{

    // vector<int> arr = {1, 2, 3, 9, 4, 6, 10, 12, 2, 7};
    // int low = 0;
    // int high = arr.size() - 1;

    // int peak_index = op_peak(arr, low, high);

    // cout<<"Peak of this array = "<<arr[peak_index]<<endl;

    // vector<vector<int>> array2 = {
    //     {10, 8, 10, 10},
    //     {14, 13, 12, 11},
    //     {15, 9, 11, 7},
    //     {16, 17, 19, 8}
    // };

    // int low = 0, high = array2.size() - 1;

    // int peak = peak_2d(array2, low, high);

    // cout<<peak<<endl;


    // int n = 5;

    // magicSquare(n);

    vector<int> arr = {1, 2, 3, 9, 4, 6, 10, 12, 2, 7};

    // selectionSort(arr);

    // quick(arr, 0, arr.size() - 1);

    // iterative(arr, 0, arr.size() - 1);

    // print(arr);


    vector<item> items = {
        {10, 100},
        {20, 120},
        {30, 140},
        {40, 150},
        {50, 200}
    };

    knapsack(items, 100);

    return 0;
}
