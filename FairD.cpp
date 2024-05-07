#include <iostream>
#include <vector>
using namespace std;

string canDivide(vector<int>& a) {
    int count1 = 0, count2 = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 1) count1++;
        else count2++;
    }
    
    if ((count1 + 2 * count2) % 2 != 0) {
        return "NO";
    }
    
    if (count2 % 2 == 0 || (count1 > 0 && count2 > 0)) {
        return "YES";
    }
    
    return "NO";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << canDivide(a) << endl;
    }
    return 0;
}
