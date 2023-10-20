#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>


using namespace std;

int dp[50001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    dp[0] = 1;

    for (int i = 1; i * i <= n; i++) {
        dp[i * i] = 1;
    }

    for (int i = 0; i <= n; i++) {
        if (dp[i] != 0) continue;

        for (int j = 1; j * j <= i; j++) {
            if (dp[i] == 0) {
                dp[i] = dp[j * j] + dp[i - j * j];
            } else {
                dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]);
            }
        }

    }
    cout << dp[n];
    return 0;
}