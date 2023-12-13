#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>


using namespace std;

int n, ans;
int grid[21][21];
int visited[21][21];
int baby = 2;
int eat;
int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};
bool is = true;

bool check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] < baby && grid[i][j] != 0) {
                return true;
            }
        }
    }
    return false;
}

void bfs() {
    int x, y;
    queue<pair<int, pair<int, int>>> q;
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 9) {
                y = i;
                x = j;
            }
        }
    }
    q.push({0, {y, x}});
    visited[y][x] = -1;
    while (!q.empty()) {
        int time = q.front().first;
        int cy = q.front().second.first;
        int cx = q.front().second.second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
                if (visited[ny][nx] != 0) {
                    continue;
                }
                if (grid[ny][nx] < baby && grid[ny][nx] != 0 && visited[ny][nx] == 0) {
                    visited[ny][nx] = time + 1;
                } else if (grid[ny][nx] <= baby) {
                    visited[ny][nx] = -1;
                    q.push({time + 1, {ny, nx}});
                }
            }
        }
    }
    int tmp = 10000000;
    pair<int, pair<int, int>> p;
    p = {0,{0,0}};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] <= 0) {
                continue;
            } else {
                if (visited[i][j] < tmp) {
                    tmp = visited[i][j];
                    p.first = tmp;
                    p.second.first = i;
                    p.second.second = j;
                }
            }

        }
    }
    if (p.first == 0){
        is = false;
        return;
    }
    grid[p.second.first][p.second.second] = 9;
    grid[y][x] = 0;
    ans += p.first;
    eat++;
    if (baby == eat) {
        baby++;
        eat = 0;
    }


}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    while (check() && is) {
        bfs();
    }
    cout << ans;
    return 0;
}