#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

int n, m, a, t, ans;
vector<int> cost;
vector<int> mem;
int dp[10001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a;
        mem.push_back(a);
    }
    for (int i = 0; i < n; i++) {
        cin >> a;
        cost.push_back(a);
        t += a;
    }


    for (int i = 0; i < n; i++) {
        for (int j = t; j >= cost[i]; j--) {
            dp[j] = max(dp[j], dp[j-cost[i]]+mem[i]);
        }
    }

    for (int i = 0; i <= t; i++) {
        if (dp[i] >= m){
            ans = i;
            break;
        }
    }
    cout << ans;
    return 0;
}