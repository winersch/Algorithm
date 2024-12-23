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

int n, m, ans = inf;
int grid[1001][1001];  // 0 red 1 pink 2 orange 3 blue 4 purple
int visited[1001][1001][4][2];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

struct node {
    int y, x, dir, orange, cost; // dir : 0 down, 1 right, 2 up, 3 left
};

node slip(node a) {
    int dir = a.dir;
    int ny = a.y;
    int nx = a.x;
    int cost = a.cost;
    while (true) {
        int ty = ny + dy[dir];
        int tx = nx + dx[dir];
        if (ty >= 0 && ty < n && tx >= 0 && tx < m && grid[ty][tx] != 0 && grid[ty][tx] != 3) {
            ny = ty;
            nx = tx;
            cost++;
            if (grid[ty][tx] == 1 || grid[ty][tx] == 2){
                break;
            }
        } else {
            break;
        }
    }
    return {ny, nx, dir, a.orange, cost};
}

void bfs() {
    memset(visited, inf, sizeof(visited));
    queue<node> q;
    q.push({0, 0, 0, 0});
    visited[0][0][0][0] = 0;

    while (!q.empty()) {
        node curr = q.front();
        q.pop();
        if (curr.y == n-1 && curr.x == m-1){
            ans = min(ans, curr.cost);
        }
        for (int i = 0; i < 4; i++) {
            int ny = curr.y + dy[i];
            int nx = curr.x + dx[i];
            int dir = i;
            int orange = curr.orange;
            int cost = curr.cost+1;
            if (ny >= 0 && ny < n && nx >= 0 && nx < m && visited[ny][nx][dir][orange] > cost && grid[ny][nx] != 0) {
                int type = grid[ny][nx];
                visited[ny][nx][dir][orange] = cost;
                switch (type) {
                    case 2:
                        orange = 1;
                        break;
                    case 3:
                        if (!orange) {
                            continue;
                        }
                        break;
                    case 4: {
                        node a = slip({ny,nx,dir,orange,cost});
                        a.orange = 0;
                        q.push(a);
                        continue;
                        break;
                    }
                    default:
                        break;
                }
                q.push({ny,nx,dir,orange, cost});
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
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    bfs();
    if (ans == inf){
        ans = -1;
    }
    cout << ans;

    return 0;
}