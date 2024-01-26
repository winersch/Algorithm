#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>

#define inf 0x3f3f3f;
using namespace std;

int n;
int matrix[501][2];
int dp[501][501];


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        matrix[i][0] = a;
        matrix[i][1] = b;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; i + j <= n; j++) {
            dp[j][i + j] = 2147483647;
            for (int k = j; k <= i + j; k++) {
                dp[j][i + j] = min(dp[j][i + j],
                                   dp[j][k] + dp[k + 1][i + j] + matrix[j][0] * matrix[k][1] * matrix[i + j][1]);
            }
        }
    }

    cout << dp[1][n];

    return 0;
}