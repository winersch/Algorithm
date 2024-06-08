#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>

using namespace std;


int n, m, roomCnt, roomArea, maxRoomArea;
bool wall[51][51][4]; // 서 북 동 남
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0}; // 서 북 동 남 순
bool visited[51][51];
int room[51][51];

void calcRoomCnt(int y, int x) {
    queue<pii> q;
    q.push({y, x});

    roomCnt++;
    room[y][x] = roomCnt;

    while (!q.empty()) {
        pii curr = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = curr.first + dy[i];
            int nx = curr.second + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
                if (room[ny][nx] == 0 && !wall[curr.first][curr.second][i]) {
                    q.push({ny, nx});
                    room[ny][nx] = roomCnt;
                }
            }
        }
    }

}

int calcRoomArea(int y, int x) {
    queue<pii> q;
    q.push({y, x});
    int area = 1;
    visited[y][x] = true;
    while (!q.empty()) {
        pii curr = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = curr.first + dy[i];
            int nx = curr.second + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
                if (!wall[curr.first][curr.second][i] && !visited[ny][nx]) {
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                    area++;
                }
            }
        }
    }
    return area;
}

void removeWall() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                if (wall[i][j][k]) {
                    memset(visited, false, sizeof(visited));
                    wall[i][j][k] = false;
                    maxRoomArea = max(maxRoomArea, calcRoomArea(i,j));
                    wall[i][j][k] = true;
                }
            }
        }
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            for (int k = 0; k < 4; k++) {
                if (a % 2 == 1) {
                    wall[i][j][k] = true;
                }
                a = a >> 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (room[i][j] == 0) {
                calcRoomCnt(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]){
                roomArea = max(roomArea, calcRoomArea(i,j));
            }
        }
    }
    removeWall();


    cout << roomCnt << "\n" << roomArea << "\n" << maxRoomArea;

    return 0;
}