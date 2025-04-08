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
#include <list>
#include <unordered_set>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n, town, fuel;
vector<pii > v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    cin >> town >> fuel;
    std::sort(v.begin(), v.end());

    int idx = 0, ans = 0;
    priority_queue<int> pq;
    while (fuel < town) {
        while (idx < n && v[idx].first <= fuel) {
            pq.push(v[idx].second);
            idx++;
        }
        if (pq.empty()) {
            cout << -1;
            return 0;
        }
        fuel += pq.top();
        pq.pop();
        ans++;
    }

    cout << ans;

    return 0;
}

