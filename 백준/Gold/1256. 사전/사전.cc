#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>
#include <numeric>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

const ll val = 1000000000;
int n, m, k;
ll dp[102][102];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;

    for (int i = 0; i < 101; i++) {
        dp[i][0] = 1;
        dp[0][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min(dp[i-1][j] + dp[i][j-1], val);
        }
    }
    if (dp[n][m] < k){
        cout << -1;
        return 0;
    }
    int cnt = n + m;

    for (int i = 0; i < cnt; i++) {
        if (n == 0){
            cout << 'z';
            continue;
        }
        if (m == 0){
            cout << 'a';
            continue;
        }

        if (k <= dp[n-1][m]){
            cout << 'a';
            n--;
        }else{
            cout << 'z';
            k -= dp[n-1][m];
            m--;
        }

    }



    return 0;
}