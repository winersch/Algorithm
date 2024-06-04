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

int n, m, s;
int dp[401][401];



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dp[a][b] = -1;
        dp[b][a] = 1;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[i][j] == 0) {
                    if (dp[i][k] == 1 && dp[k][j] == 1) {
                        dp[i][j] = 1;
                    } else if (dp[i][k] == -1 && dp[k][j] == -1) {
                        dp[i][j] = -1;
                    }
                }
            }
        }
    }
    cin >> s;
    for (int i = 0; i < s; i++) {
        int a, b;
        cin >> a >> b;
        cout << dp[a][b] << "\n";
    }

    return 0;
}