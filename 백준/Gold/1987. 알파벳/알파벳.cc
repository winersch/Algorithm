#include <iostream>

using namespace std;
int r, c, result;
char board[21][21];
int char_visited[26]; //'A' = 65

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y, int depth) {
    if (char_visited[board[x][y] - 65] == 1) {
        return;
    }
    result = max(result, depth);

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < r && ny >= 0 && ny < c && char_visited[board[nx][ny]] != 1) {
            char_visited[board[x][y] - 65] = 1;
            dfs(nx, ny, depth + 1);
            char_visited[board[x][y] - 65] = 0;
        }
    }
    return;
}

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
        }
    }


    dfs(0, 0, 1);


    cout << result;


    return 0;
}