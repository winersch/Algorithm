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

int n, m, f;
int dist[201][201];
vi v;
int round_dist[201][201];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    memset(dist, inf, sizeof(dist));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }
    cin >> f;
    for (int i = 0; i < f; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            round_dist[i][j] = dist[i][j] + dist[j][i];
            round_dist[j][i] = round_dist[i][j];
        }
    }
    vector<pii> ans;
    for (int i = 1; i <= n; i++) {
        int mx = 0;
        for(int a : v){
            if (a == i){
                continue;
            }
            mx = max(mx, round_dist[a][i]);
        }
        if (ans.empty()){
            ans.push_back({mx, i});
        }else if (ans[0].first == mx){
            ans.push_back({mx,i});
        }else if (ans[0].first > mx){
            ans.clear();
            ans.push_back({mx,i});
        }
    }
    std::sort(ans.begin(), ans.end());
    for(auto [x,y] : ans){
        cout << y << " ";
    }

    return 0;
}

