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


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>

using namespace std;

int n, m;
vector<pii> line[1001];
vector<pii> ans;
int dist[1001];
int parent[1001];

void dijkstra(){
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0,0});
    dist[0] = 0;

    while(!pq.empty()){
        int cost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        for (int i = 0; i < line[curr].size(); i++) {
            int next = line[curr][i].first;
            int ncost = cost + line[curr][i].second;

            if (dist[next] > ncost){
                parent[next] = curr;
                pq.push({ncost, next});
                dist[next] = ncost;
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
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        line[a].push_back({b,c});
        line[b].push_back({a,c});
    }
    memset(dist, inf, sizeof(dist));
    memset(parent, -1, sizeof(parent));
    dijkstra();

    for (int i = 1; i < n; i++) {
        if (parent[i] != -1){
            ans.push_back({parent[i], i});
        }
    }
    cout << ans.size() << "\n";
    for(pii a : ans){
        cout << a.first+1 << " " << a.second+1 << "\n";
    }
    return 0;
}