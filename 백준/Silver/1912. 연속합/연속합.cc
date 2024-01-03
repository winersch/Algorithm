#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>
#include <map>
#include <numeric>
#include <cmath>


using namespace std;

int n, ans = -2147483646;
vector<int> v;
int dp[100001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    dp[0] = v[0];
    ans = dp[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i-1] + v[i], v[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans;
    return 0;
}