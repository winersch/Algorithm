#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
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

vector<string> v;
int r, c;
queue<pii> s1,s2,w1,w2;
pii swan;
bool visited[1501][1501];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

void melt() {
    while(!w1.empty()){
        int cy = w1.front().first;
        int cx = w1.front().second;
        w1.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny >= 0 && ny < r && nx >= 0 && nx < c){
                if (v[ny][nx] == 'X'){
                    w2.push({ny,nx});
                    v[ny][nx] = '.';
                }
            }
        }
    }
}

bool check() {
    while(!s1.empty()){
        int cy = s1.front().first;
        int cx = s1.front().second;
        s1.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny >= 0 && ny < r && nx >= 0 && nx < c && !visited[ny][nx]){
                visited[ny][nx] = true;
                if (v[ny][nx] == 'X'){
                    s2.push({ny,nx});
                }
                if (v[ny][nx] == 'L'){
                    return true;
                }
                if (v[ny][nx] == '.'){
                    s1.push({ny,nx});
                }
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
    v.resize(r);
    for (int i = 0; i < r; i++) {
        cin >> v[i];
        for (int j = 0; j < c; j++) {
            if (v[i][j] == 'L') {
                swan = {i, j};
                w1.push({i,j});
            }
            if (v[i][j] == '.'){
                w1.push({i,j});
            }
        }
    }
    s1.push(swan);
    visited[swan.first][swan.second] = true;
    int ans = 0;
    while(true){
        if (check()){
            break;
        }
        melt();
        w1 = w2;
        s1 = s2;
        while(!w2.empty()){
            w2.pop();
        }
        while(!s2.empty()){
            s2.pop();
        }
        ans++;
    }

    cout << ans;
    return 0;
}