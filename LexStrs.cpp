#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void LexS(int n, int m, int k, string a, string b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int balance = 0;
    int i = 0, j = 0;
    
    while (i < n && j < m) {
        if (balance == k) {
            cout << b[j++];
            balance = min(balance, 0) - 1;
            continue;
        } else if (balance == -k) {
            cout << a[i++];
            balance = max(0, balance) + 1;
            continue;
        }
        
        if (a[i] < b[j]) {
            cout << a[i++];
            balance = max(0, balance) + 1;
        } else {
            cout << b[j++];
            balance = min(0, balance) - 1;
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        string a, b;
        cin >> n >> m >> k;
        cin >> a >> b;

        LexS(n, m, k, a, b);
    }

    return 0;
}
