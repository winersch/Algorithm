#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>
#include <numeric>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int r, c, n;
bool cave[102][102];
bool visited[102][102];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};


bool drop(int y, int x) {
    queue<pii > q;
    q.push({y, x});
    memset(visited, false, sizeof(visited));
    visited[y][x] = true;
    int bottom = y;
    int left = x;
    int right = x;
    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        if (cy + 1 == r) {
            return false;
        }
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny >= 0 && ny < r && nx >= 0 && nx < c && !visited[ny][nx] && cave[ny][nx]) {
                visited[ny][nx] = true;
                q.push({ny, nx});
                bottom = max(bottom, ny);
                left = min(left, nx);
                right = max(right, nx);
            }
        }
    }
    int dropDist = r - bottom - 1;
    for (int j = left; j <= right; j++) {
        for (int i = bottom; i >= 0; i--) {
            if (visited[i][j]){
                for (int k = i; k < r; k++) {
                    if (!visited[k][j] && cave[k][j]){
                        dropDist = min(dropDist, k - i - 1);
                    }
                }
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (visited[i][j]) {
                cave[i][j] = false;
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (visited[i][j]) {
                cave[i + dropDist][j] = true;
            }
        }
    }
    return true;
}

void fall(int height, int cnt) {
    bool dir;   //false = rignt, true = left;
    memset(visited, false, sizeof(visited));

    if (cnt % 2 == 0) {
        dir = true;
    } else {
        dir = false;
    }

    if (dir) {
        for (int i = 0; i < c; i++) {
            if (cave[r - height][i]) {
                cave[r - height][i] = false;
                for (int j = 0; j < 4; j++) {
                    int ny = r - height + dy[j];
                    int nx = i + dx[j];
                    if (ny >= 0 && ny < r && nx >= 0 && nx < c && cave[ny][nx] && !visited[ny][nx]){
                        if (drop(ny,nx)){
                            return;
                        }
                    }
                }
                return;
            }
        }
    } else {
        for (int i = c - 1; i >= 0; i--) {
            if (cave[r - height][i]) {
                cave[r - height][i] = false;
                for (int j = 0; j < 4; j++) {
                    int ny = r - height + dy[j];
                    int nx = i + dx[j];
                    if (ny >= 0 && ny < r && nx >= 0 && nx < c && cave[ny][nx] && !visited[ny][nx]){
                        if (drop(ny,nx)){
                            return;
                        }
                    }
                }
                return;
            }
        }
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == 'x') {
                cave[i][j] = true;
            }
        }
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        fall(a, i);

    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (cave[i][j]) {
                cout << 'x';
            } else {
                cout << '.';
            }
        }
        cout << "\n";
    }


    return 0;
}