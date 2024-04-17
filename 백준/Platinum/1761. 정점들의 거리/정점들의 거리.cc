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

vector<pair<int,int>> tree[40001];
int depth[40001];
int parent[40001][16];
int dist[40001];
int n,m;

void dfs(int node, int pare, int d, int ddist){
    depth[node] = d;
    parent[node][0] = pare;
    dist[node] = ddist;

    for (int i = 0; i < tree[node].size(); i++) {
        int next = tree[node][i].first;
        int ndist = tree[node][i].second;
        if (next != pare){
            dfs(next, node, d+1, ddist + ndist);
        }
    }
}

int lca(int u, int v){
    if (depth[u]<depth[v]){
        swap(u,v);
    }
    for (int i = 16; i >= 0 ; i--) {
        if (depth[u] - (1 << i) >= depth[v]){
            u = parent[u][i];
        }
    }
    if (u == v){
        return u;
    }
    for (int i = 15; i >= 0 ; i--) {
        if (parent[u][i] != parent[v][i]){
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int find(int u, int v){
    int l = lca(u,v);
    return dist[u] + dist[v] - 2 * dist[l];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        tree[u].push_back({v,cost});
        tree[v].push_back({u,cost});
    }

    dfs(1,0,0,0);
    for (int i = 1; i < 16; i++) {
        for (int j = 1; j <= n; j++) {
            parent[j][i] = parent[parent[j][i-1]][i-1];
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        cout << find(u,v) << "\n";
    }

    return 0;
}