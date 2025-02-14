#include <iostream>
#include <vector>
#include<cmath>
using namespace std;

struct co_ordinate{
    int x, y;
};

void print(co_ordinate& p1, co_ordinate p2, co_ordinate& p3) {
    cout << "Triangle: (" << p1.x << ", " << p1.y << "), ("
         << p2.x << ", " << p2.y << "), ("
         << p3.x << ", " << p3.y << ")\n";
}

// naive approach O(n^3)
void form_all_possible_triangles(vector<co_ordinate> &points){
    int size = points.size();

    for(int i=0; i<size; i++){
        for(int j = i+1; j<size; j++){
            for(int k=j+1; k<size; k++){
                print(points[i], points[j], points[k]);
            }
        }
    }
}

struct min_max{
    int max, min;
};

min_max calc_minAndMax(vector<int>& arr, int low, int high){
    min_max result, left, right;            // result for (min, max) overall ; left and right as recursive containers 
                                           // for recursive calls to left and right halves for min and max calculation

    if(low==high){          // 1 element
        result.max = arr[low];
        result.min = arr[low];
        return result;
    }

    if(high==low+1){
        if(arr[low]>arr[high]){
            result.max = arr[low];
            result.min = arr[high];
        }
        else{
            result.max = arr[high];
            result.min = arr[low];
        }

        return result;
    }

    int mid = (low+high) / 2;

    left = calc_minAndMax(arr, low, mid);
    right = calc_minAndMax(arr, mid+1, high);

    result.min = min(left.min, right.min);
    result.max = max(left.max, right.max);

    return result;
} 

// function to calculate determinant of a matrix 
int determinantFor2X2(vector<vector<int>> &matrix){
    return matrix[0][0] * matrix[1][1] -  matrix[0][1] * matrix[1][0];
}


int main() {

    vector<co_ordinate> points = {{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}};

    cout << "All possible triangles from the given set of points:\n";
    form_all_possible_triangles(points);

    vector<int> arr = {11,2,14,15,7,8,10,3};
    int n = arr.size();

    min_max answer = calc_minAndMax(arr, 0, n-1);

    cout<<"(Maximum, Minimum) = "<<answer.max<<", "<<answer.min<<endl;

    // vector<co_ordinate> points = {{0, 1}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {0, 4}, {4, 0}};


    return 0;
}