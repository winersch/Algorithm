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

int n, m, ans;
vector<int> up[501], down[501];
bool visited[501];

bool bfs(int a){
    queue<int> uq,dq;
    uq.push(a);
    dq.push(a);
    int cnt = 1;
    memset(visited,false,sizeof(visited));
    while(!uq.empty()){
        int curr = uq.front();
        uq.pop();
        for (int i = 0; i < up[curr].size(); i++) {
            if (visited[up[curr][i]]){
                continue;
            }
            visited[up[curr][i]] = true;
            cnt++;
            uq.push(up[curr][i]);
        }
    }
    memset(visited,false,sizeof(visited));
    while(!dq.empty()){
        int curr = dq.front();
        dq.pop();
        for (int i = 0; i < down[curr].size(); i++) {
            if (visited[down[curr][i]]){
                continue;
            }
            visited[down[curr][i]] = true;
            cnt++;
            dq.push(down[curr][i]);
        }
    }
    return cnt == n;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        up[a].push_back(b);
        down[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if(bfs(i)){
            ans++;
        }
    }

    cout << ans;

    return 0;
}