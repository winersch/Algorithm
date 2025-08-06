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
#include <ctime>
#include <iomanip>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>
#define vs vector<string>

using namespace std;

int n;
int cost[16][16];
int dp[16][1<<16];

int dfs(int curr, int visit){
    if (visit == (1<<n)-1){
        if (cost[curr][0] == 0){
            return inf;
        }
        return cost[curr][0];
    }
    if (dp[curr][visit] != -1){
        return dp[curr][visit];
    }

    dp[curr][visit] = inf;

    for (int i = 0; i < n; i++) {
        if (cost[curr][i] == 0){
            continue;
        }
        if ((visit & (1<<i)) == (1<<i)){
            continue;
        }
        dp[curr][visit] = min(dp[curr][visit], cost[curr][i] + dfs(i, visit | 1<<i));
    }
    return dp[curr][visit];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(0,1);

    return 0;
}