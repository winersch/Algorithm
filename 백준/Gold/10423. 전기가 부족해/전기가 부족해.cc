#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>
#include <numeric>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>

using namespace std;

int n, m, k, ans;
vector<pair<int, pii>> cable;
int parent[1001];

int findParent(int a) {
    if (parent[a] == n){
        return parent[a];
    }
    if (parent[a] != a) {
        parent[a] = findParent(parent[a]);
    }
    return parent[a];
}

void connect(int a, int b) {
    int pa = findParent(a);
    int pb = findParent(b);

    if (pa != pb) {
        if (pa == n) {
            parent[pb] = n;
        } else if (pb == n) {
            parent[pa] = n;
        } else if (pa < pb){
            parent[pb] = pa;
        }else{
            parent[pa] = pb;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        parent[a-1] = n;
    }
    for (int i = 0; i < m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        cable.push_back({cost, {a - 1, b - 1}});
    }

    std::sort(cable.begin(), cable.end());

    for (int i = 0; i < m; i++) {
        int cost = cable[i].first;
        int start = cable[i].second.first;
        int end = cable[i].second.second;

        if (findParent(start) != findParent(end)) {
            connect(start, end);
            ans += cost;
        }
    }

    cout << ans;

    return 0;
}