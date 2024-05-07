#include <iostream>
#include <vector>
using namespace std;

vector<int> path;

void findPath(int idx, vector<int>& connections) {
    if (idx == 1) {
        path.push_back(1);
        return;
    }
    findPath(connections[idx - 2], connections);
    path.push_back(idx);
}

int main() {
    int n;
    cin >> n;
    vector<int> connections(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> connections[i];
    }
    findPath(n, connections);
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
    return 0;
}
