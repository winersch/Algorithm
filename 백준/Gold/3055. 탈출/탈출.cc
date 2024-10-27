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
#include <set>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int r,c;
int grid[51][51];
bool visited[51][51];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
vector<pii> s;

void water(){
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (visited[i][j]){
                continue;
            }
            if (grid[i][j] == 2){
                for (int k = 0; k < 4; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if(ny >= 0 && ny < r && nx >= 0 && nx < c && !visited[ny][nx] && grid[ny][nx] == 0){
                        grid[ny][nx] = 2;
                        visited[ny][nx] = true;
                    }
                }
            }
        }
    }
}

int move(){
    memset(visited, false, sizeof(visited));
    queue<pii> q;
    for (int i = 0; i < s.size(); i++) {
        int y = s[i].first;
        int x = s[i].second;

        q.push({y,x});
    }
    s.clear();
    if (q.size() == 0){
        return 0;
    }

    while (!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= 0 && ny < r && nx >= 0 && nx < c && !visited[ny][nx] && (grid[ny][nx] == 0 || grid[ny][nx] == 3)){
                visited[ny][nx] = true;
                s.push_back({ny,nx});
                if (grid[ny][nx] == 3){
                    return 2;
                }
            }
        }
    }
    return 1;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        string st;
        cin >> st;
        for (int j = 0; j < c; j++) {
            if (st[j] == 'D'){
                grid[i][j] = 3;
            }
            if(st[j] == 'S'){
                s.push_back({i,j});
            }
            if(st[j] == 'X'){
                grid[i][j] = 1;
            }
            if(st[j] == '*'){
                grid[i][j] = 2;
            }
        }
    }
    int ans = 0;
    while(true){
        ans++;
        water();
        int result = move();
        if (result == 2){
            cout << ans;
            break;
        }
        if (result == 0 || s.size() == 0){
            cout << "KAKTUS";
            break;
        }
    }





    return 0;
}