#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>


#define inf 0x3f3f3f3f;
#define mod 1000000000;
using namespace std;

int n;
long long dp[1<<10][101][10];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    if (n < 10){
        cout << 0;
        return 0;
    }

    for (int i = 1; i <= 9; i++) {
        dp[1<<i][1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k < (1<<10); k++) {
                if (j == 0){
                    dp[k | (1<<j)][i][j] += dp[k][i-1][j+1] % mod;
                }else if (j == 9){
                    dp[k|(1<<j)][i][j] += dp[k][i-1][j-1] %mod;
                }else{
                    dp[k|(1<<j)][i][j] += (dp[k][i-1][j+1] + dp[k][i-1][j-1]) % mod;
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans = (ans + dp[(1<<10)-1][n][i]) % mod;
    }

    cout << ans;

    return 0;
}
