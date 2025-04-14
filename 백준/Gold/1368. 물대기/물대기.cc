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

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n, ans;
vector<tuple<int,int,int>> v;
int parent[301];

int findParent(int a){
    if (parent[a] == a){
        return a;
    }else{
        return parent[a] = findParent(parent[a]);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        v.push_back({a, 0, i});
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a;
            cin >> a;
            if (i == j){
                continue;
            }
            v.push_back({a,i,j});
        }
    }

    std::sort(v.begin(), v.end());

    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    int cnt = 0;

    for (int i = 0; i < v.size(); i++) {
        int cost = get<0>(v[i]);
        int a = get<1>(v[i]);
        int b = get<2>(v[i]);
        int pa = findParent(a), pb = findParent(b);
        if (pa == pb){
            continue;
        }

        parent[pa] = pb;
        ans += cost;
        cnt++;

        if (cnt == n){
            break;
        }
    }

    cout << ans;

    return 0;
}

