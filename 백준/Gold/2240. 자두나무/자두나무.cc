#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>
#include <numeric>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>

using namespace std;

int t, w, ans;
int dp[31][2][1001];
int input[1001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t >> w;
    for (int i = 1; i <= t; i++) {
        cin >> input[i];
    }

    for (int j = 0; j <= w; j++) {
        for (int i = 1; i <= t; i++) {
            if (j == 0) {
                dp[j][0][i] = dp[j][0][i - 1] + (input[i] == 1);
            } else {
                dp[j][0][i] = max(dp[j][0][i - 1] + (input[i] == 1), dp[j - 1][1][i - 1] + (input[i] == 1));
                dp[j][1][i] = max(dp[j][1][i - 1] + (input[i] == 2), dp[j - 1][0][i - 1] + (input[i] == 2));
            }
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j <= w; j++) {
            ans = max(ans, dp[j][i][t]);
        }
    }
    cout << ans;

    return 0;
}