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

int n, c, m, ans, capacity;
vector<tuple<int,int,int>> v;
int cargo[2001];

bool comp(tuple<int,int,int> x, tuple<int,int,int> y){
    return get<1>(x) < get<1>(y);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> c >> m;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back({x,y,z});
    }
    std::sort(v.begin(), v.end(), comp);
    for (int i = 0; i < v.size(); i++) {
        int maxCargo = 0;
        int from = get<0>(v[i]);
        int to = get<1>(v[i]);
        int box = get<2>(v[i]);
        for (int j = from; j < to; j++) {
            maxCargo = max(maxCargo, cargo[j]);
        }
        int tmp;
        if (maxCargo + box < c){
            tmp = box;
        }else{
            tmp = c - maxCargo;
        }
        for (int j = from; j < to; j++) {
            cargo[j] += tmp;
        }
        ans += tmp;
    }

    cout << ans;

    return 0;
}

