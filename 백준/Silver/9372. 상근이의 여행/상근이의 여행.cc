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
int parent[1001];

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

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<pii> v;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            v.push_back({a,b});
        }
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        int ans = 0;
        for(auto &[a,b] : v){
            int pa = findParent(a);
            int pb = findParent(b);
            if (pa != pb){
                parent[pb] = pa;
                ans++;
            }
        }

        cout << ans << "\n";
    }


    return 0;
}

