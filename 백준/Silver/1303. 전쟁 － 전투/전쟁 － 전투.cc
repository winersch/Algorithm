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

int n, m, ans1, ans2;
int grid[101][101];
int visited[101][101];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

void bfs(int y, int x){
    queue<pii> q;
    int cnt = 1;
    visited[y][x] = true;
    q.push({y,x});

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny >= 0 && ny < n && nx >= 0 && nx < m && !visited[ny][nx] && grid[ny][nx] == grid[y][x]){
                visited[ny][nx] = true;
                q.push({ny,nx});
                cnt++;
            }
        }
    }
    if (grid[y][x] == 1){
        ans1 += pow(cnt,2);
    }else{
        ans2 += pow(cnt,2);
    }


}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == 'W') {
                grid[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]){
                bfs(i,j);
            }
        }
    }

    cout << ans1 << " " << ans2;

}