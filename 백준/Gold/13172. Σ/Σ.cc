#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>
#include <map>
#include <numeric>


using namespace std;

long long int mod = 1000000007;
long long int ans;

long long int func(long long int x, long long int y) {
    if (y == 1) {
        return x;
    } else if (y % 2 == 1) {
        return x * func(x, y - 1) % mod;
    }
    long long int p = func(x, y / 2);
    return p * p % mod;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long int a, b;
        cin >> a >> b;
        long long g = gcd(b,a);
        b /= g;
        a /= g;
        ans += b*func(a,mod-2)%mod;
        ans %= mod;
    }
    cout << ans;
    return 0;
}