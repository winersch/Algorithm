#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>


#define inf 0x3f3f3f3f
#define mod 1234567
#define ll long long
using namespace std;

int dp[1001][10];


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t) {
        int n, ans = 0;
        cin >> n;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < 10; i++) {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= n; i++) {
            dp[i][0] = (dp[i - 1][7]) % mod;
            dp[i][1] = (dp[i - 1][2] + dp[i - 1][4]) % mod;
            dp[i][2] = (dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][5]) % mod;
            dp[i][3] = (dp[i - 1][2] + dp[i - 1][6]) % mod;
            dp[i][4] = (dp[i - 1][1] + dp[i - 1][5] + dp[i - 1][7]) % mod;
            dp[i][5] = (dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][6] + dp[i - 1][8]) % mod;
            dp[i][6] = (dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][9]) % mod;
            dp[i][7] = (dp[i - 1][4] + dp[i - 1][8] + dp[i - 1][0]) % mod;
            dp[i][8] = (dp[i - 1][5] + dp[i - 1][7] + dp[i - 1][9]) % mod;
            dp[i][9] = (dp[i - 1][6] + dp[i - 1][8]) % mod;
        }
        for (int i = 0; i < 10; i++) {
            ans += dp[n][i];
            ans %= mod;
        }
        cout << ans << "\n";
        t--;
    }


    return 0;
}