#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>
#include <stack>


using namespace std;

int inc_dp[1001];
int dec_dp[1001];
int dp[1001];
int input[1001];
int ans;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    for (int i = 0; i < n; i++) {
        inc_dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (input[i] > input[j]){
                inc_dp[i] = max(inc_dp[i], inc_dp[j]+1);
            }
        }
    }

    for (int i = n-1; i >= 0; i--) {
        dec_dp[i] = 1;
        for (int j = n-1; j >= i; j--) {
            if (input[i] > input[j]){
                dec_dp[i] = max(dec_dp[i], dec_dp[j]+1);
            }
        }
    }
    dp[0] = dec_dp[0];
    dp[n-1] = inc_dp[n-1];
    ans = max(dp[0], dp[n-1]);
    for (int i = 1; i < n-1; i++) {
        dp[i] = inc_dp[i] + dec_dp[i] -1;
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}