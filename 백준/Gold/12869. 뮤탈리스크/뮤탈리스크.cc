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


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n, ans;
int scv[3];
int dp[61][61][61];
int offset[6][3] = {{1,3,9},
               {1,9,3},
               {3,1,9},
               {3,9,1},
               {9,1,3},
               {9,3,1}};

void dfs(int a, int b, int c, int depth) {
    if (a < 0){
        a = 0;
    }
    if (b < 0){
        b = 0;
    }
    if (c < 0){
        c = 0;
    }
    if (dp[a][b][c] != 0 && dp[a][b][c] <= depth) {
        return;
    }
    dp[a][b][c] = depth;

    for (int i = 0; i < 6; i++) {
        int ta = a;
        int tb = b;
        int tc = c;
        dfs(ta - offset[i][0], tb - offset[i][1], tc - offset[i][2], depth+1);
    }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> scv[i];
    }
    dfs(scv[0], scv[1], scv[2], 0);

    cout << dp[0][0][0];

    return 0;
}