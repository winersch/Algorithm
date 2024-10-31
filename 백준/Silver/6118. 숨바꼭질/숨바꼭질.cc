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

int dist[20001];
vi edge[20001];
int n, m;
int ans, cnt, num = 200000;

void bfs(){
    queue<pii> q;
    q.push({1,0});
    dist[1] = 0;
    while(!q.empty()){
        int curr = q.front().first;
        int cost = q.front().second;
        q.pop();
        for(int next : edge[curr]){
            if (dist[next] > cost+1){
                dist[next] = cost+1;
                ans = max(ans, cost+1);
                q.push({next, cost+1});
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    memset(dist, inf, sizeof(dist));
    bfs();

    for (int i = 1; i <= n; i++) {
        if (dist[i] == ans){
            num = min(num, i);
            cnt++;
        }
    }
    cout << num << " " << ans << " " << cnt;
    return 0;
}