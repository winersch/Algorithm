#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

#define inf 0x3f3f3f
#define pii pair<int,int>

vector<int> ans;
int cave[126][126];
int cost[126][126];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

void bfs(int n){
    memset(cost, inf, sizeof(cost));
    queue<pair<pii,int>> q;
    q.push({{0,0},cave[0][0]});

    while (!q.empty()){
        pii curr = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = curr.first + dy[i];
            int nx = curr.second + dx[i];

            if (ny >= 0 && ny < n && nx >= 0 && nx < n){
                if(cost[ny][nx] > c + cave[ny][nx]){
                    cost[ny][nx] = c + cave[ny][nx];
                    q.push({{ny,nx}, c + cave[ny][nx]});
                }
            }
        }
    }
    ans.push_back(cost[n-1][n-1]);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    while(true){
        int n;
        cin >> n;
        if (n == 0){
            break;
        }
        memset(cave, 0, sizeof(cave));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> cave[i][j];
            }
        }

        bfs(n);

    }
    for (int i = 0; i < ans.size(); i++) {
        cout << "Problem " << i+1 << ": " << ans[i] << "\n";
    }


    return 0;
}