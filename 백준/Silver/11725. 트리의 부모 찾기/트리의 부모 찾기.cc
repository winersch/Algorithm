#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>


using namespace std;

int n;
int ans[100001];
int visited[100001];
vector<int> nodes[100001];

void bfs() {
    
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        for (int i = 0; i < nodes[a].size(); i++) {
            int b = nodes[a][i];
            if (!visited[b]) {
                visited[b] = 1;
                q.push(b);
                ans[b] = a;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }

    bfs();

    for (int i = 2; i <= n; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}