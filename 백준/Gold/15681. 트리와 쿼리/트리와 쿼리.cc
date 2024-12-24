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

int n, r, q;
vi tree[100001];
int dp[100001];
bool visited[100001];


int dfs(int a){
    int t = 1;
    for (int x : tree[a]) {
        if (visited[x]){
            continue;
        }
        visited[x] = true;
        t += dfs(x);
    }
    return dp[a] = t;
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> r >> q;

    for (int i = 0; i < n-1; i++) {
        int u,v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    visited[r] = true;
    dfs(r);

    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        cout << dp[a] << "\n";
    }


    return 0;
}