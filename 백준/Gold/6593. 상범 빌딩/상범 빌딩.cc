#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>


#define inf 0x3f3f3f3f
#define mod 1000000000
#define ll long long
using namespace std;

char building[31][31][31];
int l,r,c,ans;
bool visited[31][31][31];

typedef struct coord{
    int l,r,c;
};

coord start;
coord dc[6] = {{1,0,0}, {-1,0,0},{0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1}};

void bfs(){
    queue<pair<coord, int>> q;
    q.push({start,0});
    visited[start.l][start.r][start.c] = true;
    while(!q.empty()){
        coord curr = q.front().first;
        int cost = q.front().second;
        q.pop();
        for (int i = 0; i < 6; i++) {
            int nl = curr.l + dc[i].l;
            int nr = curr.r + dc[i].r;
            int nc = curr.c + dc[i].c;
            if (nl >= 0 && nl < l && nr >= 0 && nr < r && nc >= 0 && nc < c && !visited[nl][nr][nc] && building[nl][nr][nc] != '#'){
                visited[nl][nr][nc] = true;
                if (building[nl][nr][nc] == 'E'){
                    ans = cost+1;
                    return;
                }
                q.push({{nl,nr,nc},cost+1});
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    while(true){
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0){
            break;
        }
        memset(building, 0, sizeof(building));
        memset(visited, false, sizeof(visited));
        ans = 0;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                string s;
                cin >> s;
                for (int k = 0; k < c; k++) {
                    building[i][j][k] = s[k];
                    if (s[k] == 'S'){
                        start.l = i;
                        start.r = j;
                        start.c = k;
                    }
                }
            }
        }
        bfs();
        if (ans == 0){
            cout << "Trapped!";
        }else{
            cout << "Escaped in " << ans << " minute(s).";
        }
        cout << "\n";
    }


    return 0;
}