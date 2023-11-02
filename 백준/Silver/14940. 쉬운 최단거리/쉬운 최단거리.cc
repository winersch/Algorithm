#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>


using namespace std;

int n, m;
int grid[1001][1001];
int visited[1001][1001];
int ans[1001][1001];
queue<pair<pair<int,int>,int>> q;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void bfs(){
    while (!q.empty()){
        int x = q.front().first.second;
        int y = q.front().first.first;
        int cnt = q.front().second;
        ans[y][x] = cnt;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && visited[ny][nx] != 1 && grid[ny][nx] == 1){
                q.push({{ny,nx},cnt+1});
                visited[ny][nx] = 1;
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
            if (grid[i][j] == 2){
                q.push({{i,j},0});
                visited[i][j] = 1;
            }
        }
    }
    bfs();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && ans[i][j] == 0){
                cout << -1 << " ";
            }else{
                cout << ans[i][j] << " ";    
            }            
        }
        cout << "\n";
    }

    return 0;
}