#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int rgb[n][3];
    int dp[n][3];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> rgb[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        dp[0][i] = rgb[0][i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = min(dp[i-1][(j+1)%3]+rgb[i][j], dp[i-1][(j+2)%3] + rgb[i][j]);
        }
    }

    cout << min(min(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);


    return 0;
}
