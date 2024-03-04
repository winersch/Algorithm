#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>


#define inf 0x3f3f3f3f
#define mod 1000000000
#define ll long long
using namespace std;


int n, ans;
int parent[100001];
vector<pair<int, int>> x;
vector<pair<int, int>> y;
vector<pair<int, int>> z;

vector<pair<int,pair<int,int>>> edge;

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

    cin >> n;
    for (int i = 0; i < n; i++) {
        int xx, yy, zz;
        cin >> xx >> yy >> zz;
        parent[i] = i;
        x.push_back({xx, i});
        y.push_back({yy, i});
        z.push_back({zz, i});
    }
    std::sort(x.begin(), x.end());
    std::sort(y.begin(), y.end());
    std::sort(z.begin(), z.end());

    for (int i = 0; i < n-1; i++) {
        edge.push_back({x[i+1].first - x[i].first, {x[i].second, x[i+1].second}});
        edge.push_back({y[i+1].first - y[i].first, {y[i].second, y[i+1].second}});
        edge.push_back({z[i+1].first - z[i].first, {z[i].second, z[i+1].second}});
    }

    std::sort(edge.begin(), edge.end());

    for (int i = 0; i < edge.size(); i++) {
        int a = edge[i].second.first;
        int b = edge[i].second.second;

        if (findParent(a) != findParent(b)){
            select(a,b);
            ans += edge[i].first;
        }
    }

    cout << ans;

    return 0;
}
