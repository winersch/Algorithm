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
#include <list>
#include <unordered_set>
#include <sstream>
#include <ctime>
#include <iomanip>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>
#define vs vector<string>

using namespace std;

int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void bfs(int n, int a, int b, int c, int d){
    vector<vector<bool>> visited(n,vector<bool>(n, false));
    visited[a][b] = true;
    queue<pair<pii,int>> q;
    q.push({{a,b},0});
    while(!q.empty()){
        int cy = q.front().first.first;
        int cx = q.front().first.second;
        int cost = q.front().second;
        q.pop();
        if (cy == c && cx == d){
            cout << cost << "\n";
            return;
        }
        for (int i = 0; i < 8; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[ny][nx]){
                visited[ny][nx] = true;
                q.push({{ny,nx}, cost+1 });
            }
        }
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        bfs(n,a,b,c,d);
    }


    return 0;
}