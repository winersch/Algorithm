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

int n, m;
int a, b, ans;
vector<int> v[101];
int visited[101];

void bfs(){
    queue<pair<int,int>> q;
    q.push({a,0});
    visited[a] = 1;
    while(!q.empty()){
        int curr = q.front().first;
        int cnt = q.front().second;
        q.pop();
        for (int i = 0; i < v[curr].size(); i++) {
            if (v[curr][i] == b){
                ans = cnt+1;
                return;
            }
            if (visited[v[curr][i]] == 1){
                continue;
            }
            visited[v[curr][i]] = 1;
            q.push({v[curr][i], cnt+1});
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> a >> b >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bfs();
    if (ans == 0){
        ans = -1;
    }

    cout << ans;

    return 0;
}
