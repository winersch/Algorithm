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

int n, m;
vector<int> tree[100001];
int depth[100001];
int parent[100001][20];

void dfs(int node, int pare, int d) {
    depth[node] = d;
    parent[node][0] = pare;

    for (int i = 0; i < tree[node].size(); i++) {
        int next = tree[node][i];
        if (next != pare) {
            dfs(next, node, d + 1);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    for (int i = 19; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]){
            u = parent[u][i];
        }
    }
    if (u == v){
        return u;
    }
    for (int i = 19; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]){
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1,0,0);
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            parent[j][i] = parent[parent[j][i-1]][i-1];
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        cout << lca(u,v) << "\n";
    }

    return 0;
}