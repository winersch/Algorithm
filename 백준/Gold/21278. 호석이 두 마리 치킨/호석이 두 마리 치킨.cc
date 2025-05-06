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
                dist[i][j] = min(dist[i][k], dist[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }
    int a1, a2, ans = inf;
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            int d = 0;
            for (int k = 1; k <= n; k++) {
                d += min(dist[i][k], dist[j][k]) * 2;
            }
            if (d < ans){
                a1 = i;
                a2 = j;
                ans = d;
            }
        }
    }
    cout << a1 << " " << a2 << " " << ans;
    return 0;
}

