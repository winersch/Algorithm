#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int ans = 2147483647;
int house[1001][3];
int dp[1001][3];
int color[1001][3];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> house[i][0] >> house[i][1] >> house[i][2];
    }

    //1번
    dp[0][0] = house[0][0];
    dp[0][1] = 2100000000;
    dp[0][2] = 2100000000;

    for (int i = 1; i < n-1; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + house[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + house[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + house[i][2];
    }
    ans = min(ans,min(dp[n-2][2],dp[n-2][0])+house[n-1][1]);
    ans = min(ans,min(dp[n-2][0],dp[n-2][1])+house[n-1][2]);
    memset(dp,0,sizeof(dp));
    //2번
    dp[0][0] = 2100000000;
    dp[0][1] = house[0][1];
    dp[0][2] = 2100000000;

    for (int i = 1; i < n-1; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + house[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + house[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + house[i][2];
    }
    ans = min(ans,min(dp[n-2][2],dp[n-2][1])+house[n-1][0]);
    ans = min(ans,min(dp[n-2][0],dp[n-2][1])+house[n-1][2]);
    memset(dp,0,sizeof(dp));
    //3번
    dp[0][0] = 2100000000;
    dp[0][1] = 2100000000;
    dp[0][2] = house[0][2];

    for (int i = 1; i < n-1; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + house[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + house[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + house[i][2];
    }
    ans = min(ans,min(dp[n-2][2],dp[n-2][0])+house[n-1][1]);
    ans = min(ans,min(dp[n-2][2],dp[n-2][1])+house[n-1][0]);

    cout << ans;
    return 0;
}