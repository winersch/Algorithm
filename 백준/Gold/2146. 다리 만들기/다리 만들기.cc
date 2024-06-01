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


int n, ans = 300;
int m[101][101];
int t;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
bool visited[101][101];

void bfs(int y, int x){
    queue<pii> q;
    q.push({y,x});
    m[y][x] = t;
    while (!q.empty()){
        pii curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = curr.first + dy[i];
            int nx = curr.second + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < n && m[ny][nx] == 1){
                m[ny][nx] = t;
                q.push({ny,nx});
            }
        }
    }
}
void bridge(int a){
    memset(visited, false, sizeof(visited));
    queue<pair<pii,int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] == a){
                q.push({{i,j},0});
            }
        }
    }
    while (!q.empty()){
        pii curr = q.front().first;
        int cost = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = curr.first + dy[i];
            int nx = curr.second + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[ny][nx]){
                visited[ny][nx] = true;
                if (m[ny][nx] == 0){
                    q.push({{ny,nx}, cost+1});
                }else if (m[ny][nx] > 1 && m[ny][nx] != a){
                    ans = min(ans, cost);
                }
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
            cin >> m[i][j];
        }
    }
    t = 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] == 1){
                bfs(i,j);
                t++;
            }
        }
    }

    while (t > 1){
        bridge(t);
        t--;
    }

    cout << ans;

    return 0;
}