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
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>

using namespace std;

int n, k;
const int mod = 1000000003;
int dp[1001][1001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
        dp[i][1] = i;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            dp[i][j] = (dp[i-2][j-1] + dp[i-1][j]) % mod;
        }
    }
    int ans = (dp[n-1][k] + dp[n-3][k-1]) % mod;
    cout << ans;
    return 0;
}