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

using namespace std;

ll n, m, ans, tmp;
ll arr[1001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        tmp += a;
        arr[tmp % m]++;
        if (tmp % m == 0) {
            ans++;
        }
    }

    for (int i = 0; i <= m; i++) {
        ans += arr[i] * (arr[i] - 1) / 2;
    }

    cout << ans;

    return 0;
}