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

using namespace std;

bool wall[8][8];
bool visited[8][8];
int dy[9] = {0,0,1,1,1,-1,-1,-1,0};
int dx[9] = {-1,1,-1,0,1,-1,0,1,0};

void moveWall(){
    for (int i = 6; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            wall[i+1][j] = wall[i][j];
        }
    }
    for (int i = 0; i < 8; i++) {
        wall[0][i] = false;
    }
}

bool move(){
    queue<pii> q, tq;
    q.push({7,0});

    while(true){
        if (q.empty()){
            moveWall();
            q = tq;
            while(!tq.empty()){
                tq.pop();
            }
            memset(visited, false, sizeof(visited));
        }
        if (q.empty() && tq.empty()){
            break;
        }
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        if (wall[cy][cx]){
            continue;
        }
        for (int i = 0; i < 9; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8 && !wall[ny][nx] && !visited[ny][nx]){
                if (ny == 0 && nx == 7){
                    return true;
                }
                visited[ny][nx] = true;
                tq.push({ny,nx});
            }
        }
    }
    return false;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 8; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++) {
            if (s[j] == '#'){
                wall[i][j] = true;
            }
        }
    }

    cout << move();

    return 0;
}