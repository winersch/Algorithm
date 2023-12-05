#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>


using namespace std;

int r, c, t, ans;
int room[51][51];
int tmp[51][51];
int purifier;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pair<int,pair<int, int>>> q;


void diffusion() {

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (room[i][j] == -1 || room[i][j] == 0){
                continue;
            }
            int cnt = 0;
            int val = room[i][j] / 5;
            for (int k = 0; k < 4; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if (ny >= 0 && ny < r && nx >= 0 && nx < c && room[ny][nx] != -1){
                    cnt++;
                    tmp[ny][nx] += val;
                }
            }
            tmp[i][j] -= val * cnt;
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            room[i][j] += tmp[i][j];
        }
    }
    memset(tmp, 0, sizeof(tmp));
}

void purification() {
    int y1 = purifier - 1;
    int y2 = purifier;

    for (int i = y1-1; i > 0; i--) {
        room[i][0] = room[i-1][0];
    }

    for (int i = y2+1; i < r-1; i++) {
        room[i][0] = room[i+1][0];
    }

    for (int i = 0; i < c-1; i++) {
        room[0][i] = room[0][i+1];
        room[r-1][i] = room[r-1][i+1];
    }

    for (int i = 0; i <= y1; i++) {
        room[i][c-1] = room[i+1][c-1];
    }
    for (int i = r; i >= y2; i--) {
        room[i][c-1] = room[i-1][c-1];
    }

    for (int i = c-1; i > 1; i--) {
        room[y1][i] = room[y1][i-1];
        room[y2][i] = room[y2][i-1];
    }
    room[y1][1] = 0;
    room[y2][1] = 0;

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> r >> c >> t;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> room[i][j];
            if (room[i][j] == -1) {
                purifier = i;
            }
        }
    }
    for (int i = 0; i < t; i++) {
        diffusion();
        purification();
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (room[i][j] != -1) {
                ans += room[i][j];
            }
        }
    }

    cout << ans;

    return 0;
}