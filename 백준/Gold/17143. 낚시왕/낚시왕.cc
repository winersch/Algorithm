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

int r, c, m, ans;
vector<int> grid[102][102];
map<int, pair<int, pair<int, int>>> shark; // {번호, {크기,{속력,이동 방향}}}
queue<pair<int, int>> q[102];

void bfs(int idx) {
    vector<int> tmp[102][102];
    while (!q[idx].empty()) {
        pair<int, int> curr = q[idx].front();
        pair<int, int> next = curr;
        if (grid[curr.first][curr.second].empty()) {
            q[idx].pop();
            continue;
        }
        int cnum = grid[curr.first][curr.second][0];
        q[idx].pop();
        pair<int, pair<int, int>> &cshark = shark[grid[curr.first][curr.second][0]];
        grid[curr.first][curr.second].clear();

        if (cshark.second.second == 1 || cshark.second.second == 2) {
            cshark.second.first %= ((r - 1) * 2);
            for (int i = 0; i < cshark.second.first; i++) {

                if (next.first == 1) {
                    cshark.second.second = 2;
                } else if (next.first == r) {
                    cshark.second.second = 1;
                }
                if (cshark.second.second == 1) {
                    next.first--;
                } else {
                    next.first++;
                }
            }
        } else {
            cshark.second.first %= ((c - 1) * 2);
            for (int i = 0; i < cshark.second.first; i++) {
                if (next.second == 1) {
                    cshark.second.second = 3;
                } else if (next.second == c) {
                    cshark.second.second = 4;
                }
                if (cshark.second.second == 3) {
                    next.second++;
                } else {
                    next.second--;
                }
            }
        }
        tmp[next.first][next.second].push_back(cnum);
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            grid[i][j] = tmp[i][j];
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (!grid[i][j].empty()) {
                q[idx + 1].push({i, j});
            }
            if (grid[i][j].size() > 1) {
                pair<int, pair<int, int>> bigshark = shark[grid[i][j][0]];
                int bigsharknum = grid[i][j][0];
                for (int k = 1; k < grid[i][j].size(); k++) {
                    if (shark[grid[i][j][k]].first > bigshark.first) {
                        bigshark = shark[grid[i][j][k]];
                        bigsharknum = grid[i][j][k];
                    }
                }
                grid[i][j].clear();
                grid[i][j].push_back(bigsharknum);
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> r >> c >> m;
    if (m == 0) {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= m; i++) {
        int y, x, s, d, z;
        cin >> y >> x >> s >> d >> z;
        shark[i] = {z, {s, d}};
        grid[y][x].push_back(i);
        q[1].push({y, x});
    }
    for (int i = 1; i <= c; i++) {

        for (int j = 1; j <= r; j++) {
            if (!grid[j][i].empty()) {
                ans += shark[grid[j][i][0]].first;
                shark[grid[j][i][0]].first = 0;
                grid[j][i].clear();
                break;
            }
        }
        bfs(i);
    }

    cout << ans;
    return 0;
}
