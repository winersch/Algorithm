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

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int grid[16][16];
int tmp[16][16];
int attack[16][16];
int archer[16];
int n, m, d, ans;
int dy[3] = {0, -1,0};
int dx[3] = {-1,0,1};

void move(){
    for (int i = n-1; i > 0; i--) {
        for (int j = 0; j < m; j++) {
            tmp[i][j] = tmp[i-1][j];
        }
    }
    for (int i = 0; i < m; i++) {
        tmp[0][i] = 0;
    }
}

void start(){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tmp[i][j] = grid[i][j];
        }
    }
    int t = n;
    int attackCount = 0;
    while(t--){
        memset(attack,0,sizeof(attack));
        for (int i = 0; i < m; i++) {
            if (archer[i]){
                queue<pair<int,pii>> q;
                q.push({0,{n,i}});
                bool attacked = false;
                while(!q.empty() && !attacked){
                    int cy = q.front().second.first;
                    int cx = q.front().second.second;
                    int dist = q.front().first;
                    q.pop();
                    for (int j = 0; j < 3; j++) {
                        int ny = cy + dy[j];
                        int nx = cx + dx[j];
                        if (ny >= 0 && ny <= n && nx >= 0 && nx <= m && dist + 1 <= d){
                            if (tmp[ny][nx] == 1){
                                attack[ny][nx] = 1;
                                attacked = true;
                                break;
                            }else{
                                q.push({dist+1,{ny,nx}});
                            }
                        }
                    }
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (attack[i][j] == 1){
                    cnt++;
                    tmp[i][j] = 0;
                }
            }
        }
        attackCount += cnt;
        move();
    }

    ans = max(ans, attackCount);

}

void dfs(int depth, int idx){
    if (depth == 3){
        start();
        return;
    }
    for (int i = idx; i < m; i++) {
        archer[i] = 1;
        dfs(depth+1, i+1);
        archer[i] = 0;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    dfs(0,0);

    cout << ans;

    return 0;
}

