#include <iostream>
#include <queue>

using namespace std;
int n, count, count_cw;
char grid[101][101];
char grid_cw[101][101];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

queue<char> rgb_queue;

void bfs(int x, int y, char color) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == color) {
            grid[nx][ny] = 'X';
            bfs(nx, ny, color);

        }
    }
}

void bfs_cw(int x, int y, char color) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (color == 'R' || color == 'G') {
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && (grid_cw[nx][ny] == 'R' || grid_cw[nx][ny] == 'G')){
                grid_cw[nx][ny] = 'X';
                bfs_cw(nx, ny, color);
            }
        } else if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid_cw[nx][ny] == color) {
            grid_cw[nx][ny] = 'X';
            bfs_cw(nx, ny, color);
        }
    }
}

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            grid_cw[i][j] = grid[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != 'X') {
                bfs(i, j, grid[i][j]);
                count++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid_cw[i][j] != 'X') {
                bfs_cw(i, j, grid_cw[i][j]);
                count_cw++;
            }
        }
    }
    cout << count << " " << count_cw;

    return 0;
}
