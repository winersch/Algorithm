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
#define vi vector<int>

using namespace std;


int n;
int wall[33][33];
ll dp[33][33][3];
// 가로 0, 세로 1, 대각 2


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> wall[i][j];
        }
    }
    dp[0][1][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (wall[i][j]) {
                continue;
            }

            if (!wall[i][j + 1]) {
                dp[i][j + 1][0] = dp[i][j][2] + dp[i][j][0];
            }
            if (!wall[i + 1][j]) {
                dp[i + 1][j][1] = dp[i][j][2] + dp[i][j][1];
            }
            if (i + 1 < n && j + 1 < n) {
                if (!wall[i + 1][j] && !wall[i][j + 1] && !wall[i + 1][j + 1]) {
                    dp[i + 1][j + 1][2] = dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
                }
            }
        }
    }

    cout << dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2];

    return 0;
}