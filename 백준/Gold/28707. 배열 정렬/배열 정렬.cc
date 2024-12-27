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

int n, m;



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cin >> m;
    vector<pair<int,pii>> edge;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({c,{a,b}});
    }

    priority_queue<pair<int,vi>, vector<pair<int,vi>>, greater<>> pq;
    map<vi,int> dist;
    dist[v] = 0;
    pq.push({0,v});

    while(!pq.empty()){
        vi now = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (dist[now] < cost){
            continue;
        }

        for (int i = 0; i < edge.size(); i++) {
            int c = edge[i].first;
            int a = edge[i].second.first;
            int b = edge[i].second.second;
            swap(now[a-1], now[b-1]);
            if (dist.find(now) == dist.end() || dist[now] > cost + c){
                dist[now] = cost + c;
                pq.push({cost+c, now});
            }
            swap(now[a-1], now[b-1]);
        }
    }

    std::sort(v.begin(), v.end());

    if (dist.find(v) == dist.end()){
        cout << -1;
    }else{
        cout << dist[v];
    }


    return 0;
}