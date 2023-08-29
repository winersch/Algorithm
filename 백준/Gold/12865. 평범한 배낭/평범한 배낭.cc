#include <iostream>

using namespace std;

int main() {
    int n, k;
    int prod[101][2];
    int dp[101][100001];

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> prod[i][0] >> prod[i][1];

    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j >= prod[i][0]){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-prod[i][0]] + prod[i][1]);
            } else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][k];
    return 0;
}
