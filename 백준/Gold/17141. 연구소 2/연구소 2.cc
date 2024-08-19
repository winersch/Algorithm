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

int lab[51][51];
bool visited[51][51];
int n, m, ans = inf;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

void spread(){
    queue<pair<pii,int>> q;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (lab[i][j] == 3){
                visited[i][j] = true;
                q.push({{i,j},0});
            }
        }
    }
    int t = 0;

    while(!q.empty()){
        int cy = q.front().first.first;
        int cx = q.front().first.second;
        int cost = q.front().second;
        t = max(cost, t);
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < n && lab[ny][nx] != 1 && !visited[ny][nx]){
                visited[ny][nx] = true;
                q.push({{ny,nx},cost+1});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && lab[i][j] != 1){
                return;
            }
        }
    }
    ans = min(ans, t);
}

void sel(int y, int x, int depth){
    if (depth == m){
        spread();
        return;
    }

    for (int i = y; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == y && j <= x){
                continue;
            }
            if(lab[i][j] == 2){
                lab[i][j] = 3;
                sel(i,j,depth+1);
                lab[i][j] = 2;
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
        for (int j = 0; j < n; j++) {
            cin >> lab[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (lab[i][j] == 2){
                lab[i][j] = 3;
                sel(i,j,1);
                lab[i][j] = 2;
            }
        }
    }

    cout << (ans == inf ? -1 : ans);

    return 0;
}