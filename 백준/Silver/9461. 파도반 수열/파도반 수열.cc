#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>


using namespace std;
long long int dp[101];


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i < 101; i++) {
        dp[i] = dp[i-2] + dp[i-3];
    }

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << dp[n-1] << "\n";
    }

    return 0;
}