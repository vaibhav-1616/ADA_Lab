#include <iostream>
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

int main(){

    // Peak Finding...
    // An element is the peak if it is >= its immediate left and right elements.

    int arr[] = {2,8,1,9,4,6,10,12,2,7};

    int n = sizeof(arr)/sizeof(arr[0]);

    int low = 0;
    int high = n-1;

    // peak(arr, n);

    op_peak(arr, low, high);

    return 0;
}