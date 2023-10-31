#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>


using namespace std;

int n, m;
int m_sum;
int grid[501][501];
int visited[501][501];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int y, int x, int a, int depth) {
    if (depth == 4) {
        m_sum = max(m_sum, a);
    } else {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && visited[ny][nx] == 0) {
                visited[ny][nx] = 1;
                dfs(ny, nx, a + grid[ny][nx], depth + 1);
                visited[ny][nx] = 0;
            }
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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 1;
            dfs(i, j, grid[i][j], 1);
            visited[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int a = grid[i][j];
            int b = 1001;
            int cnt = 1;
            for (int k = 0; k < 4; k++) {
                int nx = j + dx[k];
                int ny = i + dy[k];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    b = min(b, grid[ny][nx]);
                    a += grid[ny][nx];
                    cnt++;
                }
            }
            if (cnt == 5) {
                m_sum = max(m_sum, a - b);
            }else if (cnt == 4){
                m_sum = max(m_sum, a);
            }
        }
    }


    cout << m_sum;
    return 0;
}