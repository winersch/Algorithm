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

int r, c, k, ans;
int m[5][5];
bool visited[5][5];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

void dfs(int y, int x, int depth){
    if (y == 0 && x == c-1){
        if (depth == k){
            ans++;
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 0 && ny < r && nx >= 0 && nx < c && m[ny][nx] == 0 && !visited[ny][nx]){
            visited[ny][nx] = true;
            dfs(ny,nx, depth+1);
            visited[ny][nx] = false;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> r >> c >> k;
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++) {
            if (s[j] == '.'){
                m[i][j] = 0;
            }else{
                m[i][j] = 1;
            }
        }
    }
    visited[r-1][0] = true;
    dfs(r-1,0,1);

    cout << ans;

    return 0;
}