#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

#define inf 0x3f3f3f
#define pii pair<int,int>

int m, n, ans = inf;
int maze[101][101];
int visited[101][101];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void bfs() {
    memset(visited, inf, sizeof(visited));
    queue<pair<int, pii>> q;
    q.push({0, {0, 0}});
    visited[0][0] = 0;

    while (!q.empty()) {
        int cy = q.front().second.first;
        int cx = q.front().second.second;
        int cost = q.front().first;
        q.pop();
        if (cy == n - 1 && cx == m - 1) {
            ans = min(ans, cost);
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
                if (maze[ny][nx] == 1) {
                    if (visited[ny][nx] > cost + 1) {
                        visited[ny][nx] = cost + 1;
                        q.push({cost + 1, {ny, nx}});
                    }
                } else {
                    if (visited[ny][nx] > cost) {
                        visited[ny][nx] = cost;
                        q.push({cost, {ny, nx}});
                    }
                }
            }
        }
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            maze[i][j] = s[j] - '0';
        }
    }
    bfs();

    cout << ans;
    return 0;
}