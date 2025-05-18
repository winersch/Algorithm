#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <numeric>
#include <set>
#include <list>
#include <unordered_set>
#include <sstream>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n, m;
vector<pii > edge[5001];
bool visited[5001];

int find(int k, int v) {
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(v);
    visited[v] = true;
    int cnt = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (auto a: edge[curr]) {
            int next = a.first;
            int usado = a.second;
            if (visited[next]) {
                continue;
            }
            visited[next] = true;
            if (usado >= k) {
                cnt++;
                q.push(next);
            }
        }
    }
    return cnt;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << find(a, b) << "\n";
    }


    return 0;
}

