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

int n;
double ans;
vector<pdd> v;

void find(int idx, pdd sum, int plus_cnt){
    if (idx == n){
        if (plus_cnt == n/2){
            double len = sqrt(sum.first * sum.first + sum.second * sum.second);
            ans = min(ans, len);
        }
        return;
    }

    if (plus_cnt < n/2){
        find(idx+1, {sum.first + v[idx].first, sum.second + v[idx].second}, plus_cnt+1);
    }

    if (idx - plus_cnt < n/2){
        find(idx+1, {sum.first - v[idx].first, sum.second - v[idx].second}, plus_cnt);
    }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        v.clear();
        ans = 1e18;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            v.push_back({a,b});
        }
        find(0, {0,0}, 0);
        cout << fixed;
        cout.precision(10);
        cout << ans << "\n";
    }


    return 0;
}

