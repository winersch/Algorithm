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

int n;
ll ans;
vector<pair<int,pii>> v;
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
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            v.push_back({a,{i,j}});
        }
    }
    std::sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        int cost = v[i].first;
        int from = v[i].second.first;
        int to = v[i].second.second;

        if (parent[findParent(from)] != parent[findParent(to)]){
            parent[findParent(to)] = findParent(from);
            ans += cost;
        }

    }
    cout << ans;
    
    return 0;
}