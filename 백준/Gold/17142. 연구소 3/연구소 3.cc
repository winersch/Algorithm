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

int n, m, ans = inf;
int lab[51][51];
int t[51][51];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
vector<pii> virus;
vector<pii> selected;

void bfs(){
    int copy[51][51];
    memset(t, -1, sizeof(t));
    queue<pii> q;

    for(auto& vir : selected){
        q.push(vir);
        t[vir.first][vir.second] = 0;
    }
    int tmp = 0;

    while(!q.empty()){
        auto [y, x] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && ny < n && nx >= 0 && nx < n && lab[ny][nx] != 1 && t[ny][nx] == -1) {
                t[ny][nx] = t[y][x] + 1;
                q.push({ny, nx});
                if (lab[ny][nx] == 0){
                    tmp = max(tmp, t[ny][nx]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (lab[i][j] == 0 && t[i][j] == -1){
                return;
            }
        }
    }
    ans = min(ans, tmp);

}

void select(int idx, int depth){
    if (depth == m){
        bfs();
        return;
    }
    for (int i = idx; i < virus.size(); i++) {
        selected.push_back(virus[i]);
        select(i+1, depth+1);
        selected.pop_back();
    }
}



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    bool a = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> lab[i][j];
            if (lab[i][j] == 0){
                a = false;
            }else if (lab[i][j] == 2){
                virus.push_back({i,j});
            }
        }
    }
    if (a){
        cout << 0;
        return 0;
    }
    select(0,0);

    if (ans == inf){
        ans = -1;
    }
    cout << ans;


    return 0;
}