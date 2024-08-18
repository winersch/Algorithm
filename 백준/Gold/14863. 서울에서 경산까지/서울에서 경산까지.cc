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

typedef struct city {
    int t1, m1, t2, m2;
};

int n, k;
int dp[101][100001];
vector<city> v;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v.push_back({a, b, c, d});
    }
    dp[0][v[0].t1] = v[0].m1;
    dp[0][v[0].t2] = max(v[0].m2, dp[0][v[0].t2]);

    for (int i = 1; i < n; i++) {
        city c = v[i];

        for (int j = k; j >= 0; j--) {
            if (dp[i - 1][j] != 0) {
                if (j + c.t1 <= k){
                    dp[i][j + c.t1] = max(dp[i][j + c.t1], dp[i - 1][j] + c.m1);
                }
                if (j + c.t2 <= k){
                    dp[i][j + c.t2] = max(dp[i][j + c.t2], dp[i - 1][j] + c.m2);
                }
            }
        }
    }
    int ans = 0;
    for (int i = k; i >= 0; i--) {
        ans = max(ans, dp[n - 1][i]);
    }

    cout << ans;

    return 0;
}