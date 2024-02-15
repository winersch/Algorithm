#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>


#define inf 0x3f3f3f3f;
#define mod 1000000000;
using namespace std;

int n;
int grid[11][11];
int l[21];
int r[21];
int ans[2];

void dfs(int y, int x, int depth, int idx) {
    if (x >= n) {
        y++;
        if (x % 2 == 0) {
            x = 1;
        } else {
            x = 0;
        }
    }

    if (y >= n) {
        ans[idx] = max(ans[idx], depth);
        return;
    }
    if (grid[y][x] == 1 && l[x - y + n - 1] != 1 && r[x + y] != 1) {
        l[x - y + n - 1] = r[x + y] = 1;
        dfs(y,x+2,depth+1,idx);
        l[x - y + n - 1] = r[x + y] = 0;
    }
    dfs(y,x+2,depth,idx);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    dfs(0, 0, 0,0);
    dfs(0,1,0,1);
    cout << ans[0] + ans[1] ;
    return 0;
}
