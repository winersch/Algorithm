#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>

using namespace std;

int r, c;
int grid[10001][501];
bool pipe[10001][501];
int dy[3] = {-1, 0, 1};

bool dfs(int y, int x){

    for (int i = 0; i < 3; i++) {
        int ny = y + dy[i];
        int nx = x + 1;
        if (ny >= 0 && ny < r && grid[ny][nx] != 1 && !pipe[ny][nx]){
            pipe[ny][nx] = true;
            if (nx+2 == c){
                return true;
            }
            if (dfs(ny, nx)){
                return true;
            }
        }
    }

    return false;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '.'){
                grid[i][j] = 0;
            }else if (s[j] == 'x'){
                grid[i][j] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < r; i++) {
        if (dfs(i,0)){
            ans++;
        }
    }

    cout << ans;

    return 0;
}