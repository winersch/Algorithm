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
#define pdd pair<double,double>

using namespace std;

int n;
vector<pdd> r;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        r.push_back({sqrt(x * x + y * y) / v, i});
    }
    std::sort(r.begin(), r.end());
    for (int i = 0; i < n; i++) {
        cout << r[i].second << "\n";
    }
    return 0;
}