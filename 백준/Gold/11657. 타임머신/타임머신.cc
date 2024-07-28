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

using namespace std;

int n, m;
vector<pair<pii, int>> node;
ll dist[501];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        node.push_back({{a, b}, c});
    }
    memset(dist, inf, sizeof(dist));
    dist[1] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < node.size(); j++) {
            int f = node[j].first.first;
            int t = node[j].first.second;
            int cost = node[j].second;

            if (dist[f] == inf){
                continue;
            }
            dist[t] = min(dist[t], dist[f] + cost);
        }
    }

    bool is = false;
    for (int i = 0; i < node.size(); i++) {
        int f = node[i].first.first;
        int t = node[i].first.second;
        int cost = node[i].second;

        if (dist[f] >= inf){
            continue;
        }
        if (dist[t] > dist[f] + cost){
            is = true;
            break;
        }
    }

    if (is){
        cout << -1;
    }else{
        for (int i = 2; i <= n; i++) {
            if (dist[i] >= inf){
                cout << -1 << "\n";
            }else{
                cout << dist[i] << "\n";
            }
        }
    }



    return 0;
}