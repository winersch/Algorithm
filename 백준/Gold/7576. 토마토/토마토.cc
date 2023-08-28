#include <iostream>
#include <queue>

using namespace std;

int tomatoes[1001][1001];
int n, m, days;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<pair<int, int>> tomato_queue;


void bfs() {
    while (!tomato_queue.empty()) {
        int curr_x, curr_y;
        curr_x = tomato_queue.front().first;
        curr_y = tomato_queue.front().second;
        tomato_queue.pop();
        for (int i = 0; i < 4; i++) {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && tomatoes[nx][ny] == 0) {
                tomatoes[nx][ny] = tomatoes[curr_x][curr_y] + 1;
                tomato_queue.push(make_pair(nx, ny));
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tomatoes[i][j];
            if (tomatoes[i][j] == 1) {
                tomato_queue.push(make_pair(i, j));
            }
        }
    }

    bfs();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (tomatoes[i][j] == 0) {
                cout << -1;
                return 0;
            }
            days = max(tomatoes[i][j], days);
        }
    }

    cout << days - 1;

    return 0;
}
