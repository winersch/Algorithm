#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>
#include <stack>


using namespace std;
#define inf 1073741820
int n, m;
vector<pair<int, int>> adj[101];
int dist[101][101];


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a - 1].push_back({b - 1, c});
    }
    memset(dist, -1, sizeof(dist));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            if (dist[i][adj[i][j].first] != -1) {
                dist[i][adj[i][j].first] = min(adj[i][j].second, dist[i][adj[i][j].first]);
            } else {
                dist[i][adj[i][j].first] = adj[i][j].second;
            }
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != -1 && dist[k][j] != -1) {
                    if (dist[i][j] == -1) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == -1){
                dist[i][j] = 0;
            }
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}