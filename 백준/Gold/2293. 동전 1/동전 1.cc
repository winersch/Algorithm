#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

int n,k;
int input[101];
int dp[10001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    sort(input, input+n);

    dp[0]= 1;

    for (int i = 0; i < n; i++) {
        for (int j = input[i]; j <= k; j++) {
            dp[j] += dp[j-input[i]];
        }
    }

    cout << dp[k];

    return 0;
}