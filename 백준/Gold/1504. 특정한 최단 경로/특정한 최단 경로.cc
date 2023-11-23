#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>
#include <stack>


using namespace std;

int n, e;
vector<pair<int, int>> v[801];
int dist[801];
int d1, d2;
#define inf 2147483647

void dijkstra(int a) {

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, a});
    dist[a] = 0;

    while (!pq.empty()) {
        int x = pq.top().second;
        int cost = pq.top().first;
        pq.pop();


        for (int i = 0; i < v[x].size(); i++) {
            int next = v[x][i].first;
            int ncost = v[x][i].second + cost;
            if (dist[next] < ncost) {
                continue;
            }
            pq.push({ncost, next});
            dist[next] = ncost;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    cin >> d1 >> d2;

    fill(dist, dist+801, inf);
    dijkstra(1);
    int ftod1 = dist[d1];
    int ftod2 = dist[d2];

    fill(dist, dist+801, inf);
    dijkstra(d1);
    int d1tod2 = dist[d2];
    int d1ton = dist[n];

    fill(dist, dist+801, inf);
    dijkstra(d2);
    int d2ton = dist[n];

    int ans1, ans2;
    bool r1 = true, r2 = true;
    if (ftod1 == inf || d1tod2 == inf || d2ton == inf){
        r1 = false;
        ans1 = inf;
    } else{
        ans1 = ftod1 + d1tod2 + d2ton;
    }

    if (ftod2 == inf || d1tod2 == inf || d1ton == inf){
        r2 = false;
        ans2 = inf;
    } else{
        ans2 = ftod2 + d1tod2 + d1ton;
    }

    if (r1 || r2){
        cout << min(ans1,ans2);
    } else{
        cout << -1;
    }


    return 0;
}