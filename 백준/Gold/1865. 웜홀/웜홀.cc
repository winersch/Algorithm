#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>


using namespace std;

int tc;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> tc;
    for (int i = 0; i < tc; i++) {
        int n, m, w;
        cin >> n >> m >> w;
        vector<pair<pair<int, int>, int>> node;
        for (int j = 0; j < m; j++) {
            int a, b, c;
            cin >> a >> b >> c;
            node.push_back({{a, b}, c});
            node.push_back({{b, a}, c});

        }
        for (int j = 0; j < w; j++) {
            int a, b, c;
            cin >> a >> b >> c;
            node.push_back({{a, b}, -c});
        }

        int dist[501];
        memset(dist, 2147483647, sizeof(dist));
        dist[1] = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < node.size(); k++) {
                int f = node[k].first.first;
                int t = node[k].first.second;
                int cost = node[k].second;

                if (dist[f] == 2147483647){
                    continue;
                }
                if (dist[t] > dist[f] + cost){
                    dist[t] = dist[f] + cost;
                }
            }
        }
        bool is = false;
        for (int j = 0; j < node.size(); j++) {
            int f = node[j].first.first;
            int t = node[j].first.second;
            int cost = node[j].second;

            if (dist[f] == 2147483647){
                continue;
            }
            if (dist[t] > dist[f] + cost){
                is = true;
                break;
            }

        }

        if (is){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}