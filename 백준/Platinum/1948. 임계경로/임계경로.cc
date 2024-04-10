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
#define mod 10007
#define ll long long
using namespace std;

int n, m, s, e, ans, cnt;
int entry[10001], dist[10001];
vector<pair<int, int>> road[10001], rroad[10001];
bool visited[10001];

void dfs(int curr) {
    if (visited[curr]){
        return;
    }
    visited[curr] = true;

    for (int i = 0; i < rroad[curr].size(); i++) {
        int next = rroad[curr][i].first;
        int d = rroad[curr][i].second;
        if (dist[curr] == dist[next]+d){
            dfs(next);
            cnt++;
        }
    }

}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        road[a].push_back({b, t});
        rroad[b].push_back({a, t});
        entry[b]++;
    }
    cin >> s >> e;

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (entry[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        for (int i = 0; i < road[a].size(); i++) {
            int next = road[a][i].first;
            int d = road[a][i].second;
            dist[next] = max(dist[next], dist[a] + d);
            entry[next]--;
            if (entry[next] == 0) {
                q.push(next);
            }
        }
    }

    dfs(e);
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dist[i]);
    }
    cout << ans << "\n" << cnt;

    return 0;
}