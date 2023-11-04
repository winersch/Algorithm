#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>


using namespace std;

int triangle[501][501];
int dp[501][501];


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }

    dp[0][0] = triangle[0][0];
    if (n == 1) {
        cout << dp[0][0];
        return 0;
    }
    dp[1][0] = dp[0][0] + triangle[1][0];
    dp[1][1] = dp[0][0] + triangle[1][1];

    for (int i = 2; i < n; i++) {
        dp[i][0] = dp[i-1][0] + triangle[i][0];
        for (int j = 1; j < i; j++) {
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
        }
        dp[i][i] = dp[i-1][i-1] + triangle[i][i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(dp[n - 1][i], ans);
    }
    cout << ans;

    return 0;
}