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


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n, m;
vi v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    int t = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        t += a;
    }
    std::sort(v.begin(), v.end());
    cin >> m;
    if (t <= m) {
        cout << v.back();
        return 0;
    }

    int low = 0, high = v.back(), mid, ans;
    while (low <= high) {
        mid = (low + high) / 2;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] < mid) {
                sum += v[i];
            } else {
                sum += mid;
            }
        }

        if (sum <= m) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }

    }

    cout << ans;

    return 0;
}

