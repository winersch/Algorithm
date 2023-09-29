#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>


using namespace std;

int n, m;
int graph[101][101];
int visited[101];
int cnt[101];
int min_num = 2147483647;
int min_user;

int bfs(int start) {
    queue<int> q;
    int sum = 0;
    q.push(start);
    visited[start] = 1;
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (graph[a][i] == 1 && visited[i] == 0) {
                cnt[i] = cnt[a] + 1;
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    for (int i = 1; i <= n ; i++) {
        sum += cnt[i];
    }
    return sum;
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    for (int i = 1; i <= n; i++) {
        int a = bfs(i);
        if (a < min_num){
            min_num = a;
            min_user = i;
        }
        memset(visited, 0, sizeof(visited));
        memset(cnt , 0, sizeof (cnt));
    }

    cout << min_user;

    return 0;
}