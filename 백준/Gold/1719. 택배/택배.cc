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
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>

using namespace std;

int n, m;
int dist[201][201];
int ans[201][201];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    memset(dist, inf, sizeof(dist));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (dist[a][b] > c) {
            ans[a][b] = b;
            ans[b][a] = a;
            dist[a][b] = c;
            dist[b][a] = c;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    ans[i][j] = ans[i][k];
                    ans[j][i] = ans[j][k];
                    dist[i][j] = dist[i][k] + dist[k][j];
                    dist[j][i] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j){
                cout << "- ";
            }else{
                cout << ans[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}