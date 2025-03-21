#include <iostream>
#include<vector>
using namespace std;

// Naive approach: TC = O(n)

int peak(int arr[], int n){
    // For peak; take seperate cases for first and last elements

    // case 1:
    int peak_ind = 0;
    bool flag = false;

    if(arr[0]>=arr[1]){
        peak_ind = 0;
        flag = true;
    }

    else if(arr[n-1]>=arr[n-2]){
        peak_ind = n-1;
        flag = true;
    }

    else{
        for(int i=1; i<n-1; i++){
            if(arr[i]>=arr[i+1] && arr[i]>=arr[i-1]){
                peak_ind = i;
                flag = true;
                break;
            }
        }
    }

    if(!flag){
        cout<<"No peak in the given array!"<<endl;
    }
    else{
        cout<<"Peak index = "<<peak_ind<<endl;
        cout<<"Peak = "<<arr[peak_ind]<<endl;
    }
}

// Optimal approach: TC = O(log n)      APPROACH JUST LIKE BINARY SEARCH

int op_peak(int arr[], int low, int high){
    int mid = (low+high) / 2;
    int p_ind = 0;

    if(arr[mid]>=arr[mid+1] && arr[mid]>= arr[mid-1]){
        p_ind = mid;
    }

    else if(arr[mid]< arr[mid-1]){
        return op_peak(arr, low, mid-1);
    }

    else{
        return op_peak(arr, mid+1, high);
    }

    cout<<"Peak index = "<<p_ind<<endl;
    cout<<"Peak = "<<arr[p_ind]<<endl;
    
}

// 2D array peak finding

int find_peak_in_2D_array(int arr[][4], int rows, int cols, int low, int high){

    // middle column

    int mid = low + (high - low) / 2;

    int max_row_ind = 0;
    for(int i=1; i<rows; i++){
        if  (arr[max_row_ind][mid] < arr[i][mid]){
            max_row_ind = i;
        }
    }

    bool is_left_peak = (mid == 0 || arr[max_row_ind][mid] >= arr[max_row_ind][mid - 1]);

    bool is_right_peak = (mid == cols - 1 || arr[max_row_ind][mid] >= arr[max_row_ind][mid + 1]);

    if (is_left_peak && is_right_peak) {
        return arr[max_row_ind][mid];
    }

    // recursively move to right
    if((mid < cols - 1) && arr[max_row_ind][mid] < arr[max_row_ind][mid+1]){
        return find_peak_in_2D_array(arr, rows, cols, mid+1, high);
    }

    // recursively move to left
    else{
        return find_peak_in_2D_array(arr, rows, cols, low, mid-1);
    }

}


// MAGIC SQUARE PROBLEM

// GRAPHS IN PYTHON FOR SELECTION SORT AND QUICK SORT


int main(){

    // Peak Finding...
    // An element is the peak if it is >= its immediate left and right elements.

    // int arr[] = {2,8,1,9,4,6,10,12,2,7};

    // int n = sizeof(arr)/sizeof(arr[0]);

    // int low = 0;
    // int high = n-1;

    // // peak(arr, n);

    // op_peak(arr, low, high);

    int arr[4][4] = {
        {10, 8, 10, 10},
        {14, 13, 12, 11},
        {15, 9, 11, 7},
        {16, 17, 19, 20}
    };

    int rows = 4;
    int cols = 4;
    int peak = find_peak_in_2D_array(arr, rows, cols, 0, cols - 1);
    cout << "Peak element in the 2D array is: " << peak << endl;


    return 0;
}