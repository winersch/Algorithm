#include <iostream>

using namespace std;

long long int dp[15][14];

int main() {
    int t;

    cin >> t;

    for (int i = 0; i < 14; i++) {
        dp[0][i] = i + 1;
    }

    for (int i = 1; i < 15; i++) {
        for (int j = 0; j < 14; j++) {
            long long int a = 0;
            for (int k = 0; k <= j; k++) {
                a+=dp[i-1][k];
            }
            dp[i][j] = a;
        }
    }


    for (int i = 0; i < t; i++) {
        int k, n;
        cin >> k >> n;
        cout << dp[k][n-1] << "\n";
    }
    return 0;
}
