#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
#define inf 0x3f3f3f3f
int dp[100001][5][5];

int move(int from, int to) {
    if (from == to) {
        return 1;
    }
    if (from == 0) {
        return 2;
    }
    if (from == 1) {
        if (to == 2 || to == 4) {
            return 3;
        } else {
            return 4;
        }
    }
    if (from == 2) {
        if (to == 1 || to == 3) {
            return 3;
        } else {
            return 4;
        }
    }
    if (from == 3) {
        if (to == 2 || to == 4) {
            return 3;
        } else {
            return 4;
        }
    }
    if (from == 4) {
        if (to == 1 || to == 3) {
            return 3;
        } else {
            return 4;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    int a,i;

    memset(dp, 0x3f, sizeof (dp));

    dp[0][0][0] = 0;
    for (i = 1; ; i++) {
        cin >> a;
        if (a == 0){
            break;
        }
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (dp[i-1][j][k] >= inf){
                    continue;
                }
                int x = move(j, a);
                int y = move(k,a);
                dp[i][j][a] = min(dp[i][j][a], dp[i-1][j][k] + y);
                dp[i][a][k] = min(dp[i][a][k], dp[i-1][j][k] + x);
            }
        }
    }
    i--;
    int ans = inf;
    for (int j = 0; j < 5; j++) {
        for (int k = 0; k < 5; k++) {
            ans = min(ans ,dp[i][j][k]);
        }
    }
    cout << ans;
    return 0;
}