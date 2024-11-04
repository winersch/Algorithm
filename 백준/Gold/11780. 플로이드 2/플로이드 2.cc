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
#include <set>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n, m;
int dist[101][101];
vector<int> route[101][101];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);



    cin >> n >> m;
    memset(dist, inf, sizeof(dist));
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    route[i][j].clear();
                    for(int a : route[i][k]){
                        route[i][j].push_back(a);
                    }
                    route[i][j].push_back(k);
                    for(int a : route[k][j]){
                        route[i][j].push_back(a);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == inf){
                cout << 0;
            }else{
                cout << dist[i][j];
            }
            cout << " ";
        }
        cout << "\n";
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || dist[i][j] == inf){
                cout << 0 << "\n";
            }else{
                cout << route[i][j].size()+2 << " ";
                cout << i << " ";
                for(int a : route[i][j]){
                    cout << a << " ";
                }
                cout << j << "\n";
            }
        }
    }

    return 0;
}