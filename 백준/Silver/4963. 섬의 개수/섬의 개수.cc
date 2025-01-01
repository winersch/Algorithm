#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

#define inf 0x3f3f3f
#define pii pair<int,int>
#define ll long long

int n,m;
bool visited[51][51];
int grid[51][51];
int dy[8] = {1,0,-1,0, 1, -1, 1, -1};
int dx[8] = {0,1,0,-1, 1, -1, -1, 1};


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    while(true){
        cin >> m >> n;
        if (n == 0 && m == 0){
            break;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        memset(visited,false,sizeof(visited));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]){
                    visited[i][j] = true;
                    ans++;
                    queue<pii> q;
                    q.push({i,j});

                    while(!q.empty()){
                        int cy = q.front().first;
                        int cx = q.front().second;
                        q.pop();

                        for (int k = 0; k < 8; k++) {
                            int ny = cy + dy[k];
                            int nx = cx + dx[k];
                            if (ny >= 0 && ny < n && nx >= 0 && nx < m && grid[ny][nx] == 1 && !visited[ny][nx]){
                                visited[ny][nx] = true;
                                q.push({ny,nx});
                            }
                        }

                    }
                }
            }
        }

        cout << ans << "\n";

    }

    return 0;
}