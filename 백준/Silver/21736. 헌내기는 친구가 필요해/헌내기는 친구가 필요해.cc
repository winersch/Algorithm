#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>


using namespace std;

int grid[601][601];
int x, y, cnt;
queue<pair<int, int>> q;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};


void bfs(){
    while (!q.empty()){
        int cx = q.front().second;
        int cy = q.front().first;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && nx < x && ny >= 0 && ny < y){
                if (grid[ny][nx] == 'O'){
                    q.push({ny,nx});
                    grid[ny][nx] = 0;
                }else if (grid[ny][nx] == 'P'){
                    q.push({ny,nx});
                    cnt++;
                    grid[ny][nx] = 0;
                }
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> y >> x;
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            char ch = cin.get();
            if (ch == '\n'){
                ch = cin.get();
            }
            grid[i][j] = ch;
            if (ch == 'I'){
                q.push({i,j});
            }
        }
    }
    bfs();
    if (cnt == 0){
        cout << "TT";
    }else {
        cout << cnt;
    }

    return 0;
}