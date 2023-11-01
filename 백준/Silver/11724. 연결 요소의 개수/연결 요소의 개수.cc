#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>


using namespace std;

int n, m;
int line[1001][1001];
int visited[1001];
int cnt;
queue<int> q;


void bfs() {
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        visited[tmp] = 1;
        for (int i = 1; i <= n; i++) {
            if (line[tmp][i] && !visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        line[a][b] = 1;
        line[b][a] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            q.push(i);
            bfs();
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}