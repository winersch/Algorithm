#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

#define inf 0x3f3f3f
#define pii pair<int,int>

int n;
int dp[1001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> dp[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i-1; j > 0; j--) {
            dp[i] = min(dp[i], dp[j] + dp[i-j]);
        }
    }

    cout << dp[n];


    return 0;
}