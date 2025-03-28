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

int m, n;
vector<vi> universe;
map<vi,int> cnt;

vi getRank(vi &arr){
    vi v;
    for (int i = 0; i < arr.size(); i++) {
        v.push_back(arr[i]);
    }
    std::sort(v.begin(), v.end());
    map<int,int> map;
    int rank = 0;
    for (int i = 0; i < v.size(); i++) {
        if (map.find(v[i]) == map.end()){
            map[v[i]] = rank++;
        }
    }

    vi res;
    for (int i = 0; i < v.size(); i++) {
        res.push_back(map[arr[i]]);
    }
    return res;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> m >> n;
    universe.resize(m);
    for (int i = 0; i < m; i++) {
        universe[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> universe[i][j];
        }
        universe[i] = getRank(universe[i]);
        cnt[universe[i]]++;
    }

    ll ans = 0;
    for (auto &[key, a] : cnt) {
        ans += (ll)a * (a-1) / 2;
    }

    cout << ans;
}

