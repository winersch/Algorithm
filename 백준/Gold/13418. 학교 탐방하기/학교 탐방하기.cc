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
#include <list>
#include <unordered_set>
#include <sstream>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n, m;
ll ans;
int parent[1001];
vector<pair<int, pii>> v;

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
    for (int i = 0; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, {a, b}});
    }
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    std::sort(v.begin(), v.end());

    int ascent = 0;

    for (auto [a, b]: v) {
        int pa = findParent(b.first);
        int pb = findParent(b.second);
        if (pa != pb) {
            parent[pb] = pa;
            if (a == 0){
                ascent++;
            }
        }
    }
    ans = pow(ascent, 2);

    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    std::sort(v.begin(), v.end(), greater<>());

    int decent = 0;

    for (auto [a, b]: v) {
        int pa = findParent(b.first);
        int pb = findParent(b.second);
        if (pa != pb) {
            parent[pb] = pa;
            if (a == 0){
                decent++;
            }
        }
    }

    ans -= pow(decent, 2);

    cout << ans;

    return 0;
}

