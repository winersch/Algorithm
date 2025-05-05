#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <numeric>
#include <set>
#include <list>
#include <unordered_set>
#include <sstream>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;


int n,m;
ll dp[2001][11];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 1; i < 2001; i++) {
        for (int j = 1; j < 11; j++) {
            if (j == 1){
                dp[i][j] = 1;
                continue;
            }
            if (i < pow(2, j-1)){
                break;
            }
            for (int k = 0; k < i/2 +1; k++) {
                dp[i][j] += dp[k][j-1];
            }
        }
    }

    int t;
    cin >> t;

    while(t--){
        cin >> n >> m;
        ll ans = 0;
        for (int i = 1; i <= m; i++) {
            ans += dp[i][n];
        }
        cout << ans << "\n";
    }

    return 0;
}

