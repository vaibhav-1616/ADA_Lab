#include <iostream>
#include <vector>
using namespace std;

vector<int> w;
vector<int> x;
int m;

void sumOfSub(int s, int k, int r) {
    x[k] = 1;

    if (s + w[k] == m) {  // found a valid subset
        for (int i = 0; i <= k; i++) {
            if (x[i] == 1) {
                cout << w[i] << " ";
            }
        }
        cout << endl;
    }
    else if (k + 1 < w.size() && s + w[k] + w[k + 1] <= m) {
        sumOfSub(s + w[k], k + 1, r - w[k]);
    }

    if (k + 1 < w.size() && (s + r - w[k] >= m) && (s + w[k + 1] <= m)) {
        x[k] = 0;
        sumOfSub(s, k + 1, r - w[k]);
    }
}

int main() {
    w = {5, 10, 12, 13, 15, 18};
    m = 30;

    int n = w.size();
    x.resize(n);

    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        total_sum += w[i];
    }

    sumOfSub(0, 0, total_sum);
    return 0;
}
