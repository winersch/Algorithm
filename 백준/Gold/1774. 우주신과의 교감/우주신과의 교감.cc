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

int n, m;
int parent[1001];
vector<pii> cord(1);
vector<pair<double,pii>> dist;
double ans;

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
    for (int i = 1; i <= n; i++) {
        int xx, yy;
        cin >> xx >> yy;
        parent[i] = i;
        cord.push_back({xx, yy});
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            double distance = sqrt(pow(cord[i].first - cord[j].first, 2) + pow(cord[i].second - cord[j].second, 2));
            dist.push_back({distance, {i, j}});
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        select(a,b);
    }
    std::sort(dist.begin(), dist.end());

    for (int i = 0; i < dist.size(); i++) {
        int a = dist[i].second.first;
        int b = dist[i].second.second;

        if (findParent(a) != findParent(b)){
            select(a,b);
            ans += dist[i].first;
        }
    }
    cout.precision(2);
    cout << fixed << ans;

    return 0;
}