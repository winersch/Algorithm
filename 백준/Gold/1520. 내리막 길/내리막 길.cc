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

int n, m;
int input[501][501];
int dp[501][501];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};


int dfs(int y, int x) {
    if (y == n - 1 && x == m - 1) {
        return 1;
    }
    if (dp[y][x] != -1) {
        return dp[y][x];
    }
    dp[y][x] = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
            if (input[ny][nx] < input[y][x]) {
                dp[y][x] += dfs(ny, nx);
            }
        }
    }
    return dp[y][x];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> input[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));

    cout << dfs(0, 0);
    return 0;
}