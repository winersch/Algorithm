#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>


#define inf 0x3f3f3f3f
#define mod 1000000007
#define ll long long
using namespace std;

int n, ans;
vector<ll> v;

ll pw(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b & 1) ret = ret * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ret;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        v.push_back(a);
    }
    std::sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        ll maxcnt = pw(2, i);
        ans += v[i] % mod * maxcnt % mod;
        ll mincnt = pw(2, n - i - 1);
        ans -= v[i] % mod * mincnt % mod;
        ans = ((ans%mod)+mod)%mod;
    }

    cout << ans;
}