#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int n, m;
vector<int> v[32001];
int entry[32001];
vector<int> ans;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        entry[b]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (entry[i] == 0) {
            q.push(i);
            ans.push_back(i);
        }
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int i = 0; i < v[curr].size(); i++) {
            int next = v[curr][i];
            entry[next]--;
            if (entry[next] == 0) {
                q.push(next);
                ans.push_back(next);
            }
        }
    }
    for (int a: ans) {
        cout << a << " ";
    }
    return 0;
}