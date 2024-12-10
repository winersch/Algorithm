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

int n, m, k, ans;
int grid[1001][1001];
bool visited[1001][1001][11];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

struct node{
    int y,x,dist,wall;
};

void bfs(){
    queue<node> q;
    q.push({0,0,0,0});
    visited[0][0][0] = true;

    while(!q.empty()){
        node curr = q.front();
        q.pop();
        if (curr.y == n-1 && curr.x == m-1){
            ans = curr.dist+1;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int ny = curr.y + dy[i];
            int nx = curr.x + dx[i];

            if (ny >= 0 && ny < n && nx >= 0 && nx < m){
                if (grid[ny][nx] == 0 && !visited[ny][nx][curr.wall]){
                    visited[ny][nx][curr.wall] = true;
                    q.push({ny,nx,curr.dist+1,curr.wall});
                }
                if (grid[ny][nx] == 1 && curr.wall < k && !visited[ny][nx][curr.wall+1]){
                    visited[ny][nx][curr.wall+1] = true;
                    q.push({ny,nx,curr.dist+1,curr.wall+1});
                }
            }
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
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            grid[i][j] = s[j] - '0';
        }
    }

    bfs();
    cout << ans;
    return 0;
}