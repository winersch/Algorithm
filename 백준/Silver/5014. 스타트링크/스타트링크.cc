#include <iostream>
#include <queue>

using namespace std;


int f, s, g, u, d;
int visited[1000003];

int bfs() {
    queue<pair<int, int>> q;
    q.push({0, s});
    visited[s] = 1;
    while (!q.empty()) {
        int curr = q.front().second;
        int cost = q.front().first;
        q.pop();
        if (curr == g) {
            return cost;
        }
        if (curr + u <= f && curr + u > 0 && visited[curr + u] == 0) {
            visited[curr + u] = 1;
            q.push({cost + 1, curr + u});
        }
        if (curr - d > 0 && curr - d <= f && visited[curr - d] == 0) {
            visited[curr - d] = 1;
            q.push({cost + 1, curr - d});
        }
    }
    return 0;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> f >> s >> g >> u >> d;

    int ans = bfs();
    if (ans == 0 && s != g) {
        cout << "use the stairs";
    } else {
        cout << ans;
    }
    return 0;
}