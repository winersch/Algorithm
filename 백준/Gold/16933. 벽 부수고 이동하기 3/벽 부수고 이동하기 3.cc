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

using namespace std;

int n, m, k, ans;
string s[1001];
bool visited[1001][1001][11][2]; // day = 0, night = 1
int dy[4] = { 0, 1, 0, -1};
int dx[4] = { 1, 0, -1, 0};

struct info {
    int y, x, day, broken, time;
};


void bfs() {
    queue<info> q;
    q.push({0, 0, 0, 0, 1});
    visited[0][0][0][0] = true;
    while (!q.empty()) {
        info curr = q.front();
        int nextDay = (curr.day == 0) ? 1 : 0;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = curr.y + dy[i];
            int nx = curr.x + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m && !visited[ny][nx][curr.broken][nextDay]) {
                if (s[ny][nx] == '0') {
                    visited[ny][nx][curr.broken][nextDay] = true;
                    q.push({ny, nx, nextDay, curr.broken, curr.time + 1});
                    if (ny == n - 1 && nx == m - 1) {
                        ans = curr.time + 1;
                        return;
                    }
                } else if (curr.day == 0 && s[ny][nx] == '1' && curr.broken < k) {
                    visited[ny][nx][curr.broken + 1][nextDay] = true;
                    q.push({ny, nx, nextDay, curr.broken + 1, curr.time + 1});
                    if (ny == n - 1 && nx == m - 1) {
                        ans = curr.time + 1;
                        return;
                    }
                }
            }
        }
        if (!visited[curr.y][curr.x][curr.broken][nextDay]) {
            visited[curr.y][curr.x][curr.broken][nextDay] = true;
            q.push({curr.y, curr.x, nextDay, curr.broken, curr.time + 1});
        }
    }
    ans = -1;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    if (n == 1 && m == 1){
        ans = 1;
    }else{
        bfs();
    }
    cout << ans;
    return 0;
}