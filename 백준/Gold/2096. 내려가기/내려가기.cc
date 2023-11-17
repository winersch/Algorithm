#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>


using namespace std;

int n;
int a, b, c;
int dp[2][6];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    cin >> a >> b >> c;
    dp[0][0] = a;
    dp[0][1] = b;
    dp[0][2] = c;
    dp[0][3] = a;
    dp[0][4] = b;
    dp[0][5] = c;
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        int j = i%2;
        dp[j][0] = max(dp[(j+1)%2][0], dp[(j+1)%2][1]) + a;
        dp[j][1] = max(dp[(j+1)%2][0], max(dp[(j+1)%2][1], dp[(j+1)%2][2])) + b;
        dp[j][2] = max(dp[(j+1)%2][1], dp[(j+1)%2][2]) + c;

        dp[j][3] = min(dp[(j+1)%2][3], dp[(j+1)%2][4]) + a;
        dp[j][4] = min(dp[(j+1)%2][3], min(dp[(j+1)%2][4], dp[(j+1)%2][5])) + b;
        dp[j][5] = min(dp[(j+1)%2][4], dp[(j+1)%2][5]) + c;
    }

    cout << max(dp[(n+1)%2][0], max(dp[(n+1)%2][1], dp[(n+1)%2][2])) << " "
         << min(dp[(n+1)%2][3], min(dp[(n+1)%2][4], dp[(n+1)%2][5]));

    return 0;
}