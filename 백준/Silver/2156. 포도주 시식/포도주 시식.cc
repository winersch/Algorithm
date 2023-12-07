#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>


using namespace std;

int n, ans;
int dp[10001];
int input[10001];


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    dp[0] = input[0];
    dp[1] = input[0] + input[1];
    dp[2] = max(input[0] + input[2], max(input[1]+input[2], input[0]+input[1]));

    for (int i = 3; i < n; i++) {
        dp[i] = max(max(dp[i-3] + input[i-1] + input[i], dp[i-2] + input[i]),dp[i-1]);
    }

    for (int i = 0; i < n; i++) {
        ans = max(dp[i], ans);
    }

    cout << ans;
    return 0;
}