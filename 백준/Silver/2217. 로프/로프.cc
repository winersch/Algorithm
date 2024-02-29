#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>


#define inf 0x3f3f3f3f
#define mod 1000000000
#define ll long long
using namespace std;

int n;
vector<int> v;
int ans;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    std::sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        ans = max(ans, v[i]*(n-i));
    }
    cout << ans;
    return 0;
}
