#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>

#define inf 0x3f3f3f;
using namespace std;

int n, m, idx = 1;
int map[1001][1001];
int ans[1001][1001];
int group[1001][1001];
int num[1000001];
bool visited[1001][1001];

queue<pair<int, int>> q;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void bfs(int i, int j) {
    queue<pair<int,int>> q2;
    q2.push({i, j});
    int tmp = 0;
    while (!q2.empty()) {
        pair<int, int> curr = q2.front();
        q2.pop();
        group[curr.first][curr.second] = idx;
        tmp++;
        for (int k = 0; k < 4; k++) {
            int ny = curr.first + dy[k];
            int nx = curr.second + dx[k];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m && map[ny][nx] == 0 && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q2.push({ny, nx});
            }
        }
    }
    num[idx] = tmp;
    idx++;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            map[i][j] = s[j] - '0';
            if (map[i][j] == 1) {
                q.push({i, j});
                ans[i][j] = 1;
                group[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0 && !visited[i][j]) {
                visited[i][j] = true;
                bfs(i, j);
            }
        }
    }

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        int tmp = 1;
        int tdx[4] = {-1,-1,-1,-1};
        for (int i = 0; i < 4; i++) {
            int ny = curr.first + dy[i];
            int nx = curr.second + dx[i];
            bool isvisited = false;
            for (int j = 0; j < 4; j++) {
                if (group[ny][nx] == tdx[j]){
                    isvisited = true;
                    break;
                }
            }
            if (ny >= 0 && ny < n && nx >= 0 && nx < m && map[ny][nx] == 0 && !isvisited) {
                tdx[i] = group[ny][nx];
                tmp += num[group[ny][nx]];
            }
        }
        ans[curr.first][curr.second] = tmp%10;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j];
        }
        cout << "\n";
    }

    return 0;
}
