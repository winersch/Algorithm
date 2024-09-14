#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>
#include <numeric>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int v, e, ans = inf;
int dist[401][401];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> v >> e;
    memset(dist, inf, sizeof(dist));
    for (int i = 0; i < e; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        dist[a][b] = c;
    }
    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            if (i==j){
                continue;
            }
            ans = min(ans, dist[i][j] + dist[j][i]);
        }
    }

    if (ans == inf){
        ans = -1;
    }
    cout << ans;

    return 0;
}