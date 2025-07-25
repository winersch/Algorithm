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
#include <ctime>
#include <iomanip>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>
#define vs vector<string>

using namespace std;



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vi> v(n);
    vi idx;
    for (int i = 0; i < n; i++) {
        idx.push_back(0);
        for (int j = 0; j < m; j++) {
            int a; cin >> a;
            v[i].push_back(a);
        }
        std::sort(v[i].begin(), v[i].end());
    }
    int ans = inf;
    while(true){
        int mx = -1;
        int mn = inf;
        int midx;

        for (int i = 0; i < n; i++) {
            if (mn > v[i][idx[i]]){
                mn = v[i][idx[i]];
                midx = i;
            }
            if (mx < v[i][idx[i]]){
                mx = v[i][idx[i]];
            }
        }

        ans = min(ans, mx - mn);
        idx[midx]++;

        if (idx[midx] == m){
            break;
        }
    }

    cout << ans;

    return 0;
}