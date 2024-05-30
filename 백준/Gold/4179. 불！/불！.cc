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

int n, m, ans = -1;
string maze[1001];
int visited[1001][1001];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void fire(){
    queue<pair<pii, int>> q;
    memset(visited, -1, sizeof(visited));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 'F'){
                q.push({{i,j},0});
                visited[i][j] = 0;
            }
        }
    }

    while (!q.empty()){
        pii curr = q.front().first;
        int t = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = curr.first + dy[i];
            int nx = curr.second + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m){
                if (visited[ny][nx] == -1 && maze[ny][nx] == '.'){
                    visited[ny][nx] = t+1;
                    q.push({{ny,nx}, t+1});
                }
            }
        }
    }
}

void escape(){
    pii location;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 'J'){
                location = {i,j};
            }
        }
    }
    queue<pair<pii,int>> q;
    q.push({location,0});

    while(!q.empty()){
        pii curr = q.front().first;
        int t = q.front().second;
        q.pop();
        if (curr.first == 0 || curr.first == n-1 || curr.second == 0 || curr.second == m-1){
            ans = t+1;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int ny = curr.first + dy[i];
            int nx = curr.second + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m){
                if ((visited[ny][nx] == -1 || visited[ny][nx] > t + 1) && maze[ny][nx] == '.'){
                    q.push({{ny,nx}, t+1});
                    maze[ny][nx] = 'J';
                }
            }
        }
    }


}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> maze[i];
    }
    fire();
    escape();
    if (ans == -1){
        cout << "IMPOSSIBLE";
    }else{
        cout << ans;
    }

    return 0;
}