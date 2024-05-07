#include <iostream>
#include <string>
using namespace std;

int minJumps(int n, int d, string s) {
    int pos = 0;
    int jumps = 0;
    while (pos < n - 1) {
        int nextPos = min(pos + d, n - 1);
        while (nextPos > pos && s[nextPos] == '0') {
            nextPos--;
        }
        if (nextPos == pos) {
            return -1;
        }
        jumps++;
        pos = nextPos;
    }
    return jumps;
}

int main() {
    int n, d;
    string s;
    cin >> n >> d;
    cin >> s;
    cout << minJumps(n, d, s) << endl;
    return 0;
}
