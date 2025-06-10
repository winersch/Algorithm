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

int dist[100][100];
int n, m;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    memset(dist, inf, sizeof (dist));
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int mid = (n+1)/2;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int heavy = 0, light = 0;
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] != inf){
                heavy++;
            }
            if (dist[j][i] != inf){
                light++;
            }
        }
        if (heavy > mid || light > mid){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
