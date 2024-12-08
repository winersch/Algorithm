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

int n, d, c;
int dp[10001];

void dijkstra(vector<pii > edge[]) {
    memset(dp, inf, sizeof(dp));
    dp[c] = 0;
    priority_queue<pii, vector<pii >, greater<pii>> pq;
    pq.push({0, c});

    while (!pq.empty()) {
        int curr = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (dp[curr] < cost) {
            continue;
        }
        for (pii a: edge[curr]) {
            int next = a.second;
            int ncost = a.first + cost;
            if (ncost < dp[next]) {
                dp[next] = ncost;
                pq.push({ncost, next});
            }
        }
    }
    int cnt = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] != inf) {
            cnt++;
            ans = max(ans, dp[i]);
        }
    }
    cout << cnt << " " << ans << "\n";
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> d >> c;
        vector<pii > edge[10001];
        for (int i = 0; i < d; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            edge[y].push_back({z, x});
        }
        dijkstra(edge);
    }

    return 0;
}