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
vector<pii> v[1001];
bool visited[1001];

int bfs(int a, int b){
    queue<pii> q;
    q.push({a,0});
    memset(visited, false, sizeof(visited));
    visited[a] = true;

    while(!q.empty()){
        int curr = q.front().first;
        int cost = q.front().second;
        q.pop();

        for(auto a : v[curr]){
            if (!visited[a.first]){
                q.push({a.first, cost + a.second});
                visited[a.first] = true;
            }
            if (a.first == b){
                return cost + a.second;
            }
        }
    }
    return -1;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n-1; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        v[a].push_back({b,cost});
        v[b].push_back({a,cost});
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << bfs(a,b) << "\n";
    }

    return 0;
}