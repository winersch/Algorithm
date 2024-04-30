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
#define mod 1234567
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>

using namespace std;

vector<pii> v[501];
vector<int> pre[501];
int dist[501];
bool erased[501][501];

int dijkstra(int start, int end) {
    priority_queue<pii, vector<pii>, greater<>> pq;
    memset(dist, inf, sizeof(dist));

    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()){
        int curr = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(cost > dist[curr]){
            continue;
        }

        for (int i = 0; i < v[curr].size(); i++) {
            int next = v[curr][i].first;
            int ncost = v[curr][i].second;
            if (erased[curr][next]){
                continue;
            }
            if (dist[next] == dist[curr] + ncost){
                pre[next].push_back(curr);
            }
            if (dist[next] > dist[curr] + ncost){
                dist[next] = dist[curr] + ncost;
                pq.push({dist[next], next});
                pre[next].clear();
                pre[next].push_back(curr);
            }
        }
    }
    return dist[end] == inf ? -1 : dist[end];
}

void erase(int start, int end){
    for (int i = 0; i < pre[end].size(); i++) {
        if (erased[pre[end][i]][end]){
            continue;
        }
        erased[pre[end][i]][end] = true;
        if (pre[end][i] != start){
            erase(start, pre[end][i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    while(n != 0 || m != 0){
        int a, b;
        cin >> a >> b;
        memset(erased, false, sizeof(erased));
        for (int i = 0; i < 501; i++) {
            v[i].clear();
        }
        for (int i = 0; i < m; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            v[x].push_back({y,z});
        }
        dijkstra(a,b);
        erase(a,b);
        cout << dijkstra(a,b) << "\n";

        cin >> n >> m;
    }



    return 0;
}