#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

int n, m, v;
int graph[1001][1001];
int visited[1001];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    cout << start << " ";
    while (!q.empty()) {
        int a = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (graph[a][i] == 1 && visited[i] == 0) {
                q.push(i);
                visited[i] = 1;
                cout << i << " ";
            }

        }
    }

}

void dfs(int start) {
    visited[start] = 1;
    cout << start << " ";

    for (int i = 1; i <= n; i++) {
        if (graph[start][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> v;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    dfs(v);
    cout << "\n";
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
    }
    bfs(v);

    return 0;
}