// Ricardo Jiménez Ureña A01636825

#include <iostream>
using namespace std;

int coinInRow(int coins[], int N) {
    // Complexity: O(N) where N is the number of coins.
    if (N == 0) return 0;
    if (N == 1) return coins[0];
    
    int dp[N];
    dp[0] = coins[0];
    dp[1] = (coins[0] > coins[1]) ? coins[0] : coins[1];
    
    for (int i = 2; i < N; i++) {
        dp[i] = (coins[i] + dp[i-2] > dp[i-1]) ? coins[i] + dp[i-2] : dp[i-1];
    }
    
    return dp[N-1];
}

int main() {
    int N;
    cout << "Enter the number of coins: ";
    cin >> N;
    
    int coins[N];
    cout << "Enter the value of each coin, one per line:\n";
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }
    
    int result = coinInRow(coins, N);
    cout << "Maximum value that can be obtained from the coins row: " << result << endl;
    return 0;
}

