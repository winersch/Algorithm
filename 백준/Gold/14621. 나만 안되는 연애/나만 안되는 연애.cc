#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>

using namespace std;

int n, m, ans;
int parent[1001];
vector<pair<int, pii>> v;
bool man[1001];

int findParent(int a) {
    if (parent[a] == a) return a;
    return parent[a] = findParent(parent[a]);
}

void select(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a > b) {
        parent[a] = b;
    } else {
        parent[b] = a;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    string s;
    cin.ignore();
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'M') {
            man[i / 2+1] = true;
        }
    }

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (man[a] != man[b]) {
            if (a > b) {
                swap(a, b);
            }
            v.push_back({c, {a, b}});
        }
    }
    std::sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        int cost = v[i].first;
        int a = v[i].second.first;
        int b = v[i].second.second;
        if (findParent(a) != findParent(b)) {
            select(a, b);
            ans += cost;
        }
    }
    int pa = findParent(1);
    for (int i = 2; i <= n; i++) {
        if (pa != findParent(i)){
            cout << -1;
            return 0;
        }
    }
    cout << ans;

    return 0;
}