#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <numeric>
#include <set>
#include <list>
#include <unordered_set>
#include <sstream>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n, m;
vector<string> v;
vector<pii > c;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int visited[101][101][4];

struct State {
    int y, x, dir, cost;

    bool operator<(const State &other) const {
        return cost > other.cost; // min-heap
    }
};

void find() {
    pii start = c[0];
    pii end = c[1];

    memset(visited, inf, sizeof(visited));
    priority_queue<State> pq;

    for (int i = 0; i < 4; i++) {
        visited[start.first][start.second][i] = 0;
        pq.push({start.first, start.second, i, 0});
    }

    while (!pq.empty()) {
        auto [y, x, dir, cost] = pq.top();
        pq.pop();

        if (visited[y][x][dir] < cost) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int ncost = cost + (dir != i);

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (v[ny][nx] == '*') continue;

            if (visited[ny][nx][i] > ncost) {
                visited[ny][nx][i] = ncost;
                pq.push({ny, nx, i, ncost});
            }

        }
    }
    int ans = inf;
    for (int i = 0; i < 4; i++) {
        ans = min(ans, visited[end.first][end.second][i]);
    }
    cout << ans;
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> m >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 'C') {
                c.push_back({i, j});
            }
        }
    }

    find();
}
