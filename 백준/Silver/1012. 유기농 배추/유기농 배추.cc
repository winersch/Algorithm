#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
int count;
int coordinate[51][51];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int x, int y, int max_x, int max_y) {
    queue<pair<int, int>> coord_queue;

    coord_queue.push(make_pair(x, y));
    while (!coord_queue.empty()) {
        int curr_x, curr_y;
        curr_x = coord_queue.front().first;
        curr_y = coord_queue.front().second;
        coord_queue.pop();
        for (int i = 0; i < 4; i++) {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];
            if (nx >= 0 && nx < max_x && ny >= 0 && ny < max_y && coordinate[nx][ny] == 1) {
                coordinate[nx][ny] = 0;
                coord_queue.push(make_pair(nx, ny));
            }
        }
    }

    return;
}

int main() {
    int test_case;
    cin >> test_case;

    for (int i = 0; i < test_case; i++) {
        count = 0;
        memset(coordinate, 0, sizeof(coordinate));
        int x, y, n;
        cin >> x >> y >> n;
        for (int j = 0; j < n; j++) {
            int input_x, input_y;
            cin >> input_x >> input_y;
            coordinate[input_x][input_y] = 1;
        }
        for (int j = 0; j < x; j++) {
            for (int k = 0; k < y; k++) {
                if (coordinate[j][k] == 1) {
                    bfs(j, k, x, y);
                    count++;
                }
            }
        }
        cout << count << "\n";
    }
    return 0;
}
