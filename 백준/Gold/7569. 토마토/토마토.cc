#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>


using namespace std;

int m, n, h;
int tomatoes[101][101][101];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dz[] = {1, -1};
queue<pair<pair<int, int>, int>> q;

void bfs() {

    while (!q.empty()) {
        int x, y, z;
        x = q.front().first.first;
        y = q.front().first.second;
        z = q.front().second;
        q.pop();
        for (int i = 0; i < 2; i++) {
            int nz = z + dz[i];
            if (nz >= 0 && nz < h && tomatoes[x][y][nz] == 0) {
                tomatoes[x][y][nz] = tomatoes[x][y][z] + 1;
                q.push({{x, y}, nz});
            }
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && tomatoes[nx][ny][z] == 0) {
                tomatoes[nx][ny][z] = tomatoes[x][y][z] + 1;
                q.push({{nx, ny}, z});
            }
        }

    }


}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> m >> n >> h;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> tomatoes[k][j][i];
                if (tomatoes[k][j][i] == 1) {
                    q.push({{k, j}, i});
                }
            }
        }
    }
    bfs();


    int days = -1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                days = max(days, tomatoes[k][j][i]);
                if (tomatoes[k][j][i] == 0) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cout << days - 1;
    return 0;
}