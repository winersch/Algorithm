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


ll n, m;
vector<int> ride_times;

ll count_kids(ll time) {
    ll kids_count = 0;
    for (int t: ride_times) {
        kids_count += time / t + 1;
    }
    return kids_count;
}

int find() {
    ll low = 0, high = n * 30;
    ll last_time = high;

    while (low <= high) {
        ll mid = (low + high) / 2;
        if (count_kids(mid) >= n) {
            last_time = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    ll kids = count_kids(last_time - 1);

    for (int i = 0; i < m; i++) {
        if (last_time % ride_times[i] == 0) {
            kids++;
        }
        if (kids == n) {
            return i + 1;
        }
    }
    return -1;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    ride_times.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> ride_times[i];
    }
    if (n <= m) {
        cout << n;
        return 0;
    }

    cout << find();

    return 0;
}