#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>


#define inf 0x3f3f3f3f
#define mod 1234567
#define ll long long
#define pii pair<int,int>

using namespace std;

int n, k;
vector<ll> v;
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ll mx = 0;
        for (int j = 0; j < a; j++) {
            ll x, y;
            cin >> x >> y;
            mx = max(mx, (x*x + y*y));
        }
        v.push_back(mx);
    }
    std::sort(v.begin(), v.end());
    cout.precision(2);

    cout << fixed << (double)v[k-1];

    return 0;
}