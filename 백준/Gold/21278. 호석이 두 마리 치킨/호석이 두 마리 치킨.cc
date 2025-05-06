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
#include <sstream>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n, m;
int dist[101][101];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    memset(dist, inf, sizeof(dist));

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }

    int ans = inf;
    vector<pii> v;
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            int d = 0;
            for (int k = 1; k <= n; k++) {
                if (k == i || k == j){
                    continue;
                }
                d += min(dist[i][k], dist[j][k]) * 2;
            }
            if (d < ans){
                v.clear();
                v.push_back({i,j});
                ans = d;
            }else if (d == ans){
                v.push_back({i,j});
            }
        }
    }
    std::sort(v.begin(), v.end());
    cout << v[0].first << " " << v[0].second << " " << ans;
    return 0;
}

