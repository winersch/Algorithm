#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>


using namespace std;

int n, m, x, ans;
vector<pair<int, int>> road[1001];
int dist[1001][1001];


void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int a = pq.top().second;
        int time = pq.top().first;
        pq.pop();

        for (int i = 0; i < road[a].size(); i++) {
            int next = road[a][i].first;
            int ntime = road[a][i].second + time;

            if (dist[start][next] == 0) {
                dist[start][next] = ntime;
                pq.push({ntime, next});
            } else if (dist[start][next] > ntime) {
                dist[start][next] = ntime;
                pq.push({ntime, next});
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        road[a - 1].push_back({b - 1, c});
    }
    for (int i = 0; i < n; i++) {
        dijkstra(i);
    }

    for (int i = 0; i < n; i++) {
        if (i == x-1){
            continue;
        }
        ans = max(ans, dist[i][x-1] + dist[x-1][i]);
    }

    cout << ans;


    return 0;
}