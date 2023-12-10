#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>


using namespace std;

int n, m, ans = 2147483647;
int grid[1001][1001];
int visited[1001][1001][2];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void bfs() {
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, 0}});
    visited[0][0][0] = 1;

    while (!q.empty()) {
        int curr = q.front().first;
        int cy = q.front().second.first;
        int cx = q.front().second.second;
        q.pop();
        if (cy == n-1 && cx == m-1){
            ans = visited[cy][cx][curr];
            return;
        }
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
                if (!curr && grid[ny][nx]) {
                    q.push({curr+1, {ny, nx}});
                    visited[ny][nx][curr+1] = visited[cy][cx][curr] + 1;
                } else if (!grid[ny][nx] && visited[ny][nx][curr] == 0) {
                    q.push({curr, {ny, nx}});
                    visited[ny][nx][curr] = visited[cy][cx][curr] + 1;
                }
            }
        }
    }
    ans = -1;
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    if (n == 1 && m == 1) {
        cout << 1;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            grid[i][j] = s[j] - '0';
        }
    }
    bfs();

    cout << ans;

    return 0;
}