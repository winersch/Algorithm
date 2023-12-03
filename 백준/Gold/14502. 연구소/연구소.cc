#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>
#include <stack>


using namespace std;

int grid[9][9];
int temp[9][9];
int n, m;
int ans;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pair<int, int>> q;

//1 벽 2 바이러스

void clear() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[i][j] = grid[i][j];
        }
    }
}

void bfs() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp[i][j] == 2) {
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m && temp[ny][nx] == 0) {
                temp[ny][nx] = 2;
                q.push({ny, nx});
            }
        }
    }
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp[i][j] == 0) {
                tmp++;
            }
        }
    }
    ans = max(ans, tmp);
}

void wall(int y, int x, int cnt) {
    if (cnt == 3) {
        clear();
        bfs();
        return;
    }
    for (int i = y*m + x; i < n*m; i++) {
        int ny = i/m;
        int nx = i%m;

        if (grid[ny][nx] == 0) {
            grid[ny][nx] = 1;
            wall(ny, nx, cnt + 1);
            grid[ny][nx] = 0;

        }

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

    clear();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) {
                grid[i][j] = 1;
                wall(i, j, 1);
                grid[i][j] = 0;
            }
        }
    }

    cout << ans;
    return 0;
}