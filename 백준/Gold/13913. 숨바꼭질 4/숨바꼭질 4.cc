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


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n, k;
bool visited[200001];
int parent[200001];
vi ans;

struct seek {
    int cost, now;
};


void bfs() {
    queue<seek> q;
    q.push({0, n});
    visited[n] = true;

    while (!q.empty()) {
        seek curr = q.front();
        q.pop();

        int cost = curr.cost + 1;
        int now = curr.now;

        if (now == k) {
            cout << cost - 1 << "\n";
            return;
        }

        if (now * 2 < 100001) {
            if (!visited[now * 2]) {
                visited[now * 2] = true;
                parent[now * 2] = curr.now;
                q.push({cost, now * 2});
            }
        }
        if (now <= 100001) {
            if (!visited[now + 1]) {
                visited[now + 1] = true;
                parent[now + 1] = curr.now;
                q.push({cost, now + 1});
            }
        }
        if (now > 0) {
            if (!visited[now - 1]) {
                visited[now - 1] = true;
                parent[now - 1] = curr.now;
                q.push({cost, now - 1});
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    bfs();
    while (true) {
        ans.push_back(k);
        if (k == n) {
            break;
        }
        k = parent[k];
    }

    std::reverse(ans.begin(), ans.end());
    for (int a: ans) {
        cout << a << " ";
    }

    return 0;
}