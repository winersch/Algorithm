#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>


#define inf 0x3f3f3f3f
#define mod 1000000000
using namespace std;

int n, m, ans;
vector<string> input;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
bool visited[51][51];

void bfs(int y1, int x1) {
    memset(visited, false, sizeof(visited));
    queue<pair<pair<int, int>, int>> q;
    q.push({{y1, x1}, 0});
    visited[y1][x1] = true;
    while (!q.empty()) {
        int cy = q.front().first.first;
        int cx = q.front().first.second;
        int curr = q.front().second;
        q.pop();
        ans = max(ans, curr);
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m && input[ny][nx] == 'L' && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push({{ny, nx}, curr+1});
            }
        }
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        input.push_back(s);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (input[i][j] == 'L') {
                bfs(i, j);
            }
        }
    }

    cout << ans;

    return 0;
}
