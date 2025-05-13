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

int n, m, ans;

void find(vector<vi> &prefer, int idx, vi &sel){
    if (sel.size() == 3){
        int t = 0;

        for (int i = 0; i < n; i++) {
            int mx = 0;
            for(int a : sel){
                mx = max(mx, prefer[i][a]);
            }
            t += mx;
        }
        ans = max(ans, t);
        return;
    }
    for (int i = idx + 1; i < m; i++) {
        sel.push_back(i);
        find(prefer, i, sel);
        sel.pop_back();
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    vector<vi> prefer(n, vi(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> prefer[i][j];
        }
    }
    vi sel;
    find(prefer,-1,sel);

    cout << ans;

    return 0;
}

