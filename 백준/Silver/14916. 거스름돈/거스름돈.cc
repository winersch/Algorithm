#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>

using namespace std;

int dp[100001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    dp[0] = dp[1] = dp[3] = -1;
    dp[2] = dp[5] = 1;
    dp[4] = dp[7] = 2;
    dp[6] = 3;
    dp[8] = 4;
    for (int i = 9; i <= n; i++) {
        dp[i] = dp[i-5]+1;
    }
    cout << dp[n];
    return 0;
}