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

int n, k;
vector<int> v;
vector<int> diff;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    for (int i = 1; i < n; i++) {
        diff.push_back(abs(v[i] - v[i-1]));
    }
    std::sort(diff.begin(), diff.end());
    ll ans = 0;
    for (int i = 0; i < n-k; i++) {
        ans += diff[i];
    }
    cout << ans;
    return 0;
}