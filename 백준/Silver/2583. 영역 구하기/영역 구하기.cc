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
#define vi vector<int>

using namespace std;

int n, m, k;
bool grid[101][101];
bool visited[101][101];
vi ans;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

void drawRect(int x1, int y1, int x2, int y2){

    for (int i = y1; i < y2; i++) {
        for (int j = x1; j < x2; j++) {
            grid[i][j] = true;
        }
    }
}

void bfs(int y, int x){
    queue<pii> q;
    q.push({y,x});
    int area = 1;
    visited[y][x] = true;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m && !grid[ny][nx] && !visited[ny][nx]){
                area++;
                q.push({ny,nx});
                visited[ny][nx] = true;
            }
        }
    }
    ans.push_back(area);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        drawRect(a,b,c,d);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!grid[i][j] && !visited[i][j]){
                bfs(i,j);
            }
        }
    }
    std::sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(int a : ans){
        cout << a << " ";
    }

    return 0;
}