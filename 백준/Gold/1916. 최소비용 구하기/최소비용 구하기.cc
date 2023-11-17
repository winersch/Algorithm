#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>


using namespace std;

vector<pair<int, int>> v[1001];
int dist[1001];
int n, m;
int start, dest;

void dijkstra() {

    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (dist[cur] < cost) {
            continue;
        }
        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int ncost = cost + v[cur][i].second;
            if (dist[next] > ncost) {
                dist[next] = ncost;
                pq.push({ncost, next});
            }
        }
    }
    cout << dist[dest];
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    cin >> start >> dest;
    fill(dist, dist + n + 1, 2147483647);

    dijkstra();

    return 0;
}