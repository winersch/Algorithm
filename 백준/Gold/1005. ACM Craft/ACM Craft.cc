#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int cost[1001];
int ans[1001];
int entry[1001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        memset(cost, 0, sizeof(cost));
        memset(ans, 0, sizeof(ans));
        memset(entry,0,sizeof(entry));
        int n, k;
        cin >> n >> k;
        for (int j = 1; j <= n; j++) {
            cin >> cost[j];
        }
        int a, b;
        vector<int> graph[1001];
        for (int j = 0; j < k; j++) {
            cin >> a >> b;
            graph[a].push_back(b);
            entry[b]++;
        }
        queue<int> q;
        for (int j = 1; j <= n; j++) {
            if (entry[j]==0){
                q.push(j);
                ans[j] = cost[j];
            }
        }
        while (!q.empty()){
            int curr = q.front();
            q.pop();
            for (int j = 0; j < graph[curr].size(); j++) {
                int next = graph[curr][j];
                entry[next]--;
                ans[next] = max(ans[next], ans[curr] + cost[next]);
                if (entry[next] == 0){
                    q.push(next);
                }
            }
        }
        int dest;
        cin >> dest;
        cout << ans[dest]<< "\n";
    }

    return 0;
}