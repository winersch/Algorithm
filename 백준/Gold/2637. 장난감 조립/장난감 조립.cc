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
vector<pii > v[101];
int cost[101][101];
int indegree[101];


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        indegree[b]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0){
            q.push(i);
            cost[i][i] = 1;
        }
    }

    while (!q.empty()){
        int curr= q.front();
        q.pop();

        for (int i = 0; i < v[curr].size(); i++) {
            for (int j = 1; j <= n; j++) {
                cost[j][v[curr][i].first] += v[curr][i].second * cost[j][curr];
            }
            indegree[v[curr][i].first]--;
            if (indegree[v[curr][i].first] == 0){
                q.push(v[curr][i].first);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (v[i].empty()){
            cout << i << " " << cost[n][i] << "\n";
        }
    }

    return 0;
}