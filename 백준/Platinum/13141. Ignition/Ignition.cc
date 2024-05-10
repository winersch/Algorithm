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
vector<pii> v[201];
int dist[201][201];
int longestAdj[201][201];

double find(){
    double shortestTime = inf, longestTime, spentTime, remain;
    int edge;

    for (int i = 1; i <= n; i++) {
        longestTime = 0;

        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                edge = longestAdj[j][k];
                if (edge != -1){
                    remain = edge - (dist[i][k] - dist[i][j]);
                    if (remain > 0){
                        spentTime = remain/2 + dist[i][k];
                        longestTime = max(spentTime, longestTime);
                    }
                }
            }
        }
        shortestTime = min(longestTime, shortestTime);
    }
    return shortestTime;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    cin >> n >> m;

    memset(longestAdj, -1, sizeof(longestAdj));
    memset(dist, -1, sizeof(dist));

    for (int i = 0; i < m; i++) {
        int s, e, l;
        cin >> s >> e >> l;
        v[s].push_back({e,l});
        v[e].push_back({s,l});
        longestAdj[s][e] = max(longestAdj[s][e], l);
        longestAdj[e][s] = max(longestAdj[e][s], l);
    }

    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (dist[i][v[i][j].first] != -1){
                dist[i][v[i][j].first] = min(v[i][j].second, dist[i][v[i][j].first]);
            }else{
                dist[i][v[i][j].first] = v[i][j].second;
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != -1 && dist[k][j] != -1) {
                    if (dist[i][j] == -1) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }


    cout.precision(1);
    cout << fixed << find();

    return 0;
}