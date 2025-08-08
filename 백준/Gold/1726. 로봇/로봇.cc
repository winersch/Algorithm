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
#include <ctime>
#include <iomanip>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>
#define vs vector<string>

using namespace std;

int grid[101][101];
int n, m, ans;
int visited[101][101][4];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int turn_left[4] = {3, 2, 0, 1};
int turn_right[4] = {2, 3, 1, 0};

struct status {
    int y, x, dir;

    bool operator==(const status& other) const{
        return y == other.y && x == other.x && dir == other.dir;
    }
};

status st, ed;

void bfs() {
    queue<pair<status, int>> q;
    q.push({st, 0});
    memset(visited, inf, sizeof(visited));
    visited[st.y][st.x][st.dir] = 0;

    while(!q.empty()){
        status curr = q.front().first;
        int cost = q.front().second;
        q.pop();
        if (curr == ed){
            ans = cost;
            return;
        }
        if (visited[curr.y][curr.x][curr.dir] < cost){
            continue;
        }
        for (int j = 1; j <= 3; j++) {
            int ny = curr.y + dy[curr.dir] * j;
            int nx = curr.x + dx[curr.dir] * j;
            if (ny >= 0 && ny < n && nx >= 0 && nx < m){
                if (grid[ny][nx] == 1){
                    break;
                }
                if (visited[ny][nx][curr.dir] > cost + 1){
                    visited[ny][nx][curr.dir] = cost + 1;
                    q.push({{ny,nx,curr.dir}, cost + 1});
                }
            }
        }
        if (visited[curr.y][curr.x][turn_left[curr.dir]] > cost + 1) {
            visited[curr.y][curr.x][turn_left[curr.dir]] = cost + 1;
            q.push({{curr.y, curr.x, turn_left[curr.dir]}, cost + 1});
        }
        if (visited[curr.y][curr.x][turn_right[curr.dir]] > cost + 1) {
            visited[curr.y][curr.x][turn_right[curr.dir]] = cost + 1;
            q.push({{curr.y, curr.x, turn_right[curr.dir]}, cost + 1});
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
    int a, b, c;
    cin >> a >> b >> c;
    st = {a-1, b-1, c-1};
    cin >> a >> b >> c;
    ed = {a-1, b-1, c-1};
    bfs();

    cout << ans;

    return 0;
}