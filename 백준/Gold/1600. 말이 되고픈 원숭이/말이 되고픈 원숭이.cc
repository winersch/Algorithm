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

int grid[201][201];
bool visited[201][201][31];
int k, n, m, ans = -1;
int dy1[8] = {-2, -1, 1, 2,  2,  1, -1, -2};
int dx1[8] = { 1,  2, 2, 1, -1, -2, -2, -1};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

struct node{
    int y, x, cnt, cost;
};

void bfs(){
    queue<node> q;
    q.push({0,0,k,0});
    visited[0][0][k] = true;

    while(!q.empty()){
        node curr = q.front();
        q.pop();
        if (curr.y == n-1 && curr.x == m-1){
            ans = curr.cost;
            return;
        }
        if (curr.cnt > 0){
            for (int i = 0; i < 8; i++) {
                int ny = curr.y + dy1[i];
                int nx = curr.x + dx1[i];

                if (ny >= 0 && ny < n && nx >= 0 && nx < m && grid[ny][nx] != 1 && !visited[ny][nx][curr.cnt-1]){
                    visited[ny][nx][curr.cnt-1] = true;
                    q.push({ny,nx,curr.cnt-1,curr.cost+1});
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            int ny = curr.y + dy[i];
            int nx = curr.x + dx[i];

            if (ny >= 0 && ny < n && nx >= 0 && nx < m && grid[ny][nx] != 1 && !visited[ny][nx][curr.cnt]){
                visited[ny][nx][curr.cnt] = true;
                q.push({ny,nx,curr.cnt,curr.cost+1});
            }
        }
    }


}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> k >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    bfs();
    cout << ans;

    return 0;
}