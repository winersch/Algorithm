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

int n, m, ans, cnt;
int grid[101][101];
bool visited[101][101];
vector<pii > v;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

bool bfs() {
    memset(visited, false, sizeof(visited));
    queue<pii> q;
    q.push({0,0});
    int t = 0;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m && !visited[ny][nx]){
                visited[ny][nx] = true;
                if (grid[ny][nx] == 0){
                    q.push({ny,nx});
                }else{
                    grid[ny][nx] = 0;
                    t++;
                }
            }
        }
    }
    if (t == 0){
        return false;
    }
    cnt = t;
    ans++;
    return true;
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
    while(bfs()){}
    cout << ans << "\n" << cnt;
    return 0;
}