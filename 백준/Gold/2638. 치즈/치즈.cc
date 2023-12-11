#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>


using namespace std;

int n, m, ans;
int grid[101][101];
int visited[101][101];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool melt() {
    bool is_molten = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && visited[i][j] >= 2) {
                grid[i][j] = 0;
                is_molten = true;
            }
        }
    }
    if (!is_molten) {
        return is_molten;
    } else {
        ans++;
        return is_molten;
    }
}


void bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    memset(visited, 0, sizeof(visited));

    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
                if (grid[ny][nx] == 0 && !visited[ny][nx]) {
                    visited[ny][nx] = 1;
                    q.push({ny, nx});
                } else if (grid[ny][nx] == 1) {
                    visited[ny][nx]++;
                }
            }
        }
    }
    if (melt()) {
        bfs();
    } else {
        return;
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    bfs();
    cout << ans;

    return 0;
}