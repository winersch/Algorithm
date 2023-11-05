#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>


using namespace std;

int input[2][100001];
int dp[2][100001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> input[0][j];
        }
        for (int j = 0; j < n; j++) {
            cin >> input[1][j];
        }

        dp[0][0] = input[0][0];
        dp[1][0] = input[1][0];
        dp[0][1] = input[0][1] + dp[1][0];
        dp[1][1] = input[1][1] + dp[0][0];

        for (int j = 2; j < n; j++) {
            dp[0][j] = input[0][j] + max(dp[1][j-1], dp[1][j-2]);
            dp[1][j] = input[1][j] + max(dp[0][j-1], dp[0][j-2]);
        }
        int result = max(dp[0][n-1], dp[1][n-1]);
        cout << result << "\n";
        memset(dp, 0, sizeof(dp));
        memset(input, 0, sizeof(input));
    }


    return 0;
}