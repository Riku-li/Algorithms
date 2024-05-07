#include <iostream>
#include <vector>
using namespace std;

bool binary_search(const vector<int>& A, int k) {
    int left = 0;
    int right = A.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (A[mid] == k) {
            return true;
        } else if (A[mid] < k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        cout << binary_search(A, k) << endl;
    }

    return 0;
}
