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

int n, m, ans;
int grid[301][301];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

bool check(){
    int cnt = 1;
    int visited[301][301] = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] > 0){
                if (cnt > 1 && !visited[i][j]){
                    return true;
                }
                queue<pii> q;
                q.push({i,j});
                visited[i][j] = cnt;
                while(!q.empty()){
                    int cy = q.front().first;
                    int cx = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int ny = cy + dy[k];
                        int nx = cx + dx[k];
                        if (ny >= 0 && ny < n && nx >= 0 && nx < m && !visited[ny][nx] && grid[ny][nx] > 0){
                            visited[ny][nx] = cnt;
                            q.push({ny,nx});
                        }
                    }
                }
                cnt++;
            }
        }
    }
    return false;
}

bool melt(){
    bool res = false;
    int tmp[301][301] = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] > 0){
                for (int k = 0; k < 4; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if (ny >= 0 && ny < n && nx >= 0 && nx < m){
                        if (grid[ny][nx] == 0){
                            tmp[i][j]++;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] -= tmp[i][j];
            if (grid[i][j] < 0){
                grid[i][j] = 0;
            }
            if (grid[i][j] > 0){
                res = true;
            }
        }
    }
    ans++;
    return res;
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

    while(true){
        if (check()){
            break;
        }
        if (!melt()){
            ans = 0;
            break;
        }
    }

    cout << ans;

    return 0;
}