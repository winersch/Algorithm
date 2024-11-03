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
#include <set>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int grid[101][101];
int visited[101][101][2];
int n,m,t,ans = 10001;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

void bfs(){
    queue<pair<pii,pii>> q;
    q.push({{0,0},{0,0}});
    visited[0][0][0] = true;

    while(!q.empty()){
        int currTime = q.front().first.first;
        int gram = q.front().first.second;
        int y = q.front().second.first;
        int x = q.front().second.second;
        q.pop();
        if (currTime > t){
            return;
        }
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && ny < n && nx >= 0 && nx < m && !visited[ny][nx][gram]){
                visited[ny][nx][gram] = true;
                if (grid[ny][nx] == 2){
                    visited[ny][nx][true] = true;
                    q.push({{currTime+1,true},{ny,nx}});
                    continue;
                }
                if (!gram && grid[ny][nx] == 1){
                    continue;
                }
                if (ny == n-1 && nx == m-1){
                    ans = min(ans, currTime+1);
                    return;
                }
                q.push({{currTime+1,gram},{ny,nx}});
                visited[ny][nx][gram] = true;

            }

        }
    }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    bfs();
    if (ans == 10001){
        cout << "Fail";
    }else{
        cout << ans;
    }

    return 0;
}