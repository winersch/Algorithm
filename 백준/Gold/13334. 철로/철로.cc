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

int n, len, ans;
priority_queue<int, vector<int>, greater<>> pq;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({min(a, b), max(a, b)});
    }
    cin >> len;
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
        int home = v[i].first;
        int workplace = v[i].second;
        if (workplace - home <= len) {
            pq.push(home);
        } else {
            continue;
        }
        while (!pq.empty()) {
            if (pq.top() < workplace - len) {
                pq.pop();
            } else {
                ans = max(ans, (int) pq.size());
                break;
            }
        }
    }
    cout << ans;
}