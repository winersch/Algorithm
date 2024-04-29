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
#define mod 1234567
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>

using namespace std;

int dp[46][2];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int k;
    cin >> k;

    dp[1][0] = 0;
    dp[1][1] = 1;

    for (int i = 2; i <= k; i++) {
        dp[i][0] = dp[i-1][1];
        dp[i][1] = dp[i-1][1] + dp[i-1][0];
    }

    cout << dp[k][0] << " " << dp[k][1];



    return 0;
}