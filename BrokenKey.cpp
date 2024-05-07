#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        set<char> workingButtons;

        for (int i = 0; i < s.length(); i++) {
            if (i + 1 < s.length() && s[i] == s[i + 1]) {
                i++;
            } else {
                workingButtons.insert(s[i]);
            }
        }

        for (char c : workingButtons) {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}
