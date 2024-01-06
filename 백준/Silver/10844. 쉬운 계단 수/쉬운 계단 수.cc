#include <iostream>

using namespace std;

int dp[101][10];
int n;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i < 10; i++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0){
                dp[i][j] = dp[i-1][j+1];
            }else if (j == 9){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
            }
            dp[i][j] %= 1000000000;
        }
    }

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += dp[n][i];
        ans %= 1000000000;
    }
    cout << ans;
    return 0;
}