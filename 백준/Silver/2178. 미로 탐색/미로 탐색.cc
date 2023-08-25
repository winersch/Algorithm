#include <iostream>
#include <queue>

using namespace std;
int coordinate[101][101];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


int bfs(int x, int y, int max_x, int max_y) {
    queue<pair<pair<int, int>,int>> coord_queue;

    coord_queue.push(make_pair(make_pair(x, y),1));
    while (!coord_queue.empty()) {
        int curr_x, curr_y, count;
        curr_x = coord_queue.front().first.first;
        curr_y = coord_queue.front().first.second;
        count = coord_queue.front().second;
        if (curr_x == max_x-1 && curr_y == max_y-1){
            return count;
        }
        coord_queue.pop();
        for (int i = 0; i < 4; i++) {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];
            if (nx >= 0 && nx < max_x && ny >= 0 && ny < max_y && coordinate[nx][ny] == 1) {
                coordinate[nx][ny] = 0;
                coord_queue.push(make_pair(make_pair(nx, ny),count+1));
            }
        }
    }
    return -1;
}

int main() {
    int x,y;
    cin >> x >> y;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            char input;
            cin >> input;
            coordinate[i][j] = (input - '0');
        }
    }
    cout << bfs(0,0,x,y);

    return 0;
}
