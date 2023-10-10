#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>


using namespace std;

int n, cnt = 1;
int grid[26][26];
int visited[26][26];
vector<pair<int, int>> v1;
vector<int> v;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    visited[y][x] = 1;
    q.push({y, x});
    int num = 1;

    while (!q.empty()) {
        int ty = q.front().first;
        int tx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = ty + dy[i];
            int nx = tx + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < n && grid[ny][nx] != 0 && visited[ny][nx] != 1) {
                grid[ny][nx] = cnt;
                visited[ny][nx] = 1;
                q.push({ny, nx});
                num++;
            }
        }

    }
    v.push_back(num);
    cnt++;
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char ch = cin.get();
            if (ch == '\n') {
                ch = cin.get();
            }
            grid[i][j] = ch - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && grid[i][j] != 0) {
                bfs(i, j);
            }
        }
    }
    sort(v.begin(), v.end());
    cout << cnt - 1 << "\n";
    for (int a: v) {
        cout << a << "\n";

    }

    return 0;
}