#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>
#include <numeric>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

ll n, m, ans;
ll cost[100001];

ll check(ll t) {
    ll tmp = 0;
    for (int i = 0; i < n; i++) {
        tmp += t / cost[i];
    }
    return tmp;
}

void find() {
    ll low = 0, high = m * cost[0], mid;
    ans = high;
    while (low <= high) {
        mid = (low + high) / 2;
        ll tmp = check(mid);
        if (tmp >= m) {
            high = mid - 1;
            ans = min(ans, mid);
        } else {
            low = mid + 1;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    sort(cost, cost+n);
    find();

    cout << ans;

    return 0;
}