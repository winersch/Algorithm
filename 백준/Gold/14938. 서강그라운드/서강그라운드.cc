#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>
#include <stack>


using namespace std;

int n, m, r, ans;
int item[101];
int adj[101][101];
int dist[101][101];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> r;
    for (int i = 0; i < n; i++) {
        cin >> item[i];
    }
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < r; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a-1][b-1] = c;
        dist[b-1][a-1] = c;
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j){
                dist[i][j] = 0;
            }
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[k][i] == -1 || dist[k][j] == -1){
                    continue;
                }
                if (dist[i][j] == -1){
                    dist[i][j] = dist[k][i] + dist[k][j];
                    dist[j][i] = dist[i][j];
                }else{
                    dist[i][j] = min(dist[i][j], dist[k][i] + dist[k][j]);
                    dist[j][i] = dist[i][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int tmp = 0;
        for (int j = 0; j < n; j++) {
            if (dist[i][j] <= m && dist[i][j] != -1){
                tmp+= item[j];
            }
        }
        ans = max(ans,tmp);
    }

    cout << ans;
    return 0;
}