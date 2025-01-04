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


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n, ans;
int grid[101][101];
bool visited[101][101];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

void bfs(int a, int y, int x) {
    queue<pii > q;
    q.push({y, x});

    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[ny][nx] && grid[ny][nx] > a) {
                visited[ny][nx] = true;
                q.push({ny,nx});
            }
        }
    }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < 101; i++) {
        int cnt = 0;
        memset(visited,false,sizeof(visited));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (grid[j][k] > i && !visited[j][k]) {
                    cnt++;
                    bfs(i, j, k);
                }
            }
        }
        ans = max(ans, cnt);
    }

    cout << ans;
    return 0;
}