#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        int left = 0, right = n - 1;
        while (left <= right) {
            if (left == right) {
                cout << b[left] << " ";
            } else {
                cout << b[left] << " " << b[right] << " ";
            }
            left++;
            right--;
        }
        cout << endl;
    }

    return 0;
}
