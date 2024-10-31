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
#include <set>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n, m, ans;
vector<pair<int, pii>> v;
int parent[1001];

int findParent(int a) {
    if (parent[a] == a) {
        return a;
    }
    return parent[a] = findParent(parent[a]);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b) {
            swap(a, b);
        }
        v.push_back({c, {a, b}});
    }
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    std::sort(v.begin(), v.end());
    for (auto a: v) {
        int cost = a.first;
        int n1 = a.second.first;
        int n2 = a.second.second;
        if (findParent(n1) != findParent(n2)) {
            ans += cost;
            parent[findParent(n2)] = findParent(n1);
        }
    }

    cout << ans;

    return 0;
}