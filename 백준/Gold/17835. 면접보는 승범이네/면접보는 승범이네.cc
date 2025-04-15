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

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n, m, k;
vector<pll> v[100001];
vector<ll> iv;
ll dist[100001];

void dijkstra(){
    priority_queue<pll, vector<pll>, greater<>> pq;
    for (int i = 0; i < iv.size(); i++) {
        dist[iv[i]] = 0;
        pq.push({0, iv[i]});
    }

    while(!pq.empty()){
        ll curr = pq.top().second;
        ll cost = pq.top().first;
        pq.pop();

        if (dist[curr] < cost){
            continue;
        }

        for (int i = 0; i < v[curr].size(); i++) {
            ll next = v[curr][i].first;
            ll ncost = cost + v[curr][i].second;
            if (dist[next] > ncost){
                dist[next] = ncost;
                pq.push({ncost, next});
            }
        }
    }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        v[b].push_back({a,c});
    }
    for (int i = 0; i < k; i++) {
        ll a;
        cin >> a;
        iv.push_back(a);
    }
    fill(dist, dist+100001, 1e18);
    dijkstra();

    ll ans = 0, long_dist = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == inf){
            continue;
        }
        if (dist[i] > long_dist){
            long_dist = dist[i];
            ans = i;
        }
    }
    cout << ans << "\n" << long_dist;

    return 0;
}

