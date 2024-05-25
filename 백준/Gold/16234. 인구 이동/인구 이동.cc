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

int n, l, r, ans, cnt;
int country[51][51];
int visited[51][51];
int moved[51][51];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
vector<int> average;

bool check() {
    queue<pii > q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            q.push({i, j});
        }
    }
    while (!q.empty()) {
        pii curr = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = curr.first + dy[i];
            int nx = curr.second + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
                if (visited[ny][nx]) {
                    continue;
                }
                int diff = abs(country[curr.first][curr.second] - country[ny][nx]);
                if (diff >= l && diff <= r) {
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
            }
        }
    }
    bool checked = false;
    for (int i = 0; i < n; i++) {
        if (checked) {
            break;
        }
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) {
                checked = true;
                break;
            }
        }
    }
    memset(visited, false, sizeof(visited));
    return checked;
}

void bfs(int y, int x) {
    int tmp = 0;
    int num = 0;
    queue<pii > q;
    q.push({y, x});
    visited[y][x] = true;
    tmp += country[y][x];
    num++;
    while (!q.empty()) {
        pii curr = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = curr.first + dy[i];
            int nx = curr.second + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
                if (visited[ny][nx] || moved[ny][nx]) {
                    continue;
                }
                int diff = abs(country[curr.first][curr.second] - country[ny][nx]);
                if (diff >= l && diff <= r) {
                    visited[ny][nx] = true;
                    num++;
                    q.push({ny, nx});
                }
            }
        }
    }
    if (num == 1){
        cnt--;
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == y && j == x){
                moved[i][j] = cnt;
                continue;
            }
            if (visited[i][j]) {
                tmp += country[i][j];
                moved[i][j] = cnt;
            }
        }
    }
    average.push_back(tmp / num);
}

void move() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (moved[i][j] > 0) {
                country[i][j] = average[moved[i][j] - 1];
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> country[i][j];
        }
    }
    while (check()) {
        cnt = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (moved[i][j] == 0) {
                    bfs(i, j);
                    memset(visited, false, sizeof(visited));
                    cnt++;
                }
            }
        }
        move();
        memset(moved, false, sizeof(moved));
        average.clear();
        ans++;
    }

    cout << ans;
    return 0;
}