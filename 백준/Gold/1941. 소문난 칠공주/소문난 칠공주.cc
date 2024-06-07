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

string seat[5];
int ans;
bool visited[5][5];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
vector<pair<int, int>> pos;

bool isConnected(){
    queue<pii> q;
    q.push(pos[0]);
    bool tmp[5][5] = {false};
    tmp[pos[0].first][pos[0].second] = true;
    int cnt = 1;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && ny < 5 && nx >= 0 && nx < 5 && !tmp[ny][nx]) {
                if (find(pos.begin(), pos.end(), make_pair(ny, nx)) != pos.end()) {
                    tmp[ny][nx] = true;
                    q.push({ny, nx});
                    cnt++;
                }
            }
        }
    }
    return cnt == 7;
}


void dfs(int idx, int depth, int cnt) {
    if (depth == 7) {
        if (cnt >= 4 && isConnected()) {
            ans++;
        }
        return;
    }

    for (int i = idx; i < 25; i++) {
        int y = i / 5;
        int x = i % 5;

        if (!visited[y][x]){
            visited[y][x] = true;
            pos.push_back({y,x});
            if (seat[y][x] == 'S'){
                dfs(i+1, depth+1, cnt+1);
            }else{
                dfs(i+1, depth+1, cnt);
            }
            pos.pop_back();
            visited[y][x] = false;
        }
    }

}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 5; i++) {
        cin >> seat[i];
    }

    dfs(0, 0, 0);
    cout << ans;
    return 0;
}