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

int n, m, k, ans;
vector<pii> v;
int parent[10001];

int findParent(int a){
    if (parent[a] == a){
        return a;
    }
    return parent[a] = findParent(parent[a]);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        v.push_back({a,i});
    }

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (findParent(a) != findParent(b)){
            parent[findParent(b)] = findParent(a);
        }
    }
    sort(v.begin(), v.end());
    for (auto a : v) {
        if (parent[findParent(a.second)] != 0){
            parent[findParent(a.second)] = 0;
            ans += a.first;
            if (ans > k){
                ans = -1;
                break;
            }
        }
    }

    if (ans == -1){
        cout << "Oh no";
    }else{
        cout << ans;
    }

    return 0;
}