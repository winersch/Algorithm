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

int n;
int chapsum[501];
int dp[501][501];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            chapsum[i] = chapsum[i-1] + a;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n-i; j++) {
                int a = j+i;
                dp[j][a] = inf;
                for (int k = j; k < a; k++) {
                    dp[j][a] = min(dp[j][a], dp[j][k] + dp[k+1][a] + chapsum[a] - chapsum[j-1]);
                }
            }
        }
        cout << dp[1][n] << "\n";
    }

    return 0;
}