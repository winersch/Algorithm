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

int n, m, ans, start, dest;
vector<pii> v[10001];
bool visited[10001];

bool bfs(int limit){
    queue<int> q;
    memset(visited, false, sizeof(visited));
    visited[start] = true;
    q.push(start);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if (curr == dest){
            return true;
        }
        for (auto &next : v[curr]){
            int nnode = next.first;
            int ncost = next.second;

            if (!visited[nnode] && ncost >= limit){
                visited[nnode] = true;
                q.push(nnode);
            }
        }
    }
    return false;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    cin >> start >> dest;

    int low = 1, high = 1000000000;

    while(low <= high){
        int mid = (low + high) / 2;
        if (bfs(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }


    cout << ans;

    return 0;
}