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

int n, m, ans;
int board[51][51];
int dp[51][51];
bool visited[51][51];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool dfs(int y, int x) {
    if (visited[y][x]) {
        ans = -1;
        return false;
    }
    if (dp[y][x] != -1) {
        return true;
    }

    visited[y][x] = true;
    dp[y][x] = 0;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i] * board[y][x];
        int nx = x + dx[i] * board[y][x];
        if (ny >= 0 && ny < n && nx >= 0 && nx < m && board[ny][nx] != 0) {
            if (!dfs(ny, nx)) {
                return false;
            }
            dp[y][x] = max(dp[y][x], dp[ny][nx] + 1);
        }
    }

    visited[y][x] = false;
    return true;
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == 'H') {
                board[i][j] = 0;
            } else {
                board[i][j] = s[j] - '0';
            }
        }
    }
    memset(dp, -1, sizeof(dp));

    dfs(0, 0);

    if (dfs(0, 0)) {
        cout << dp[0][0] + 1 << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}