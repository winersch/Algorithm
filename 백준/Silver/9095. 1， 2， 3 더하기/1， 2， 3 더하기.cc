#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    int input;
    cin >> input;
    int *dp;
    dp = new int[11];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i < 11; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    for (int i = 1; i <= input; i++) {
        int j;
        cin >> j;
        cout << dp[j] << "\n";
    }
    return 0;
}
