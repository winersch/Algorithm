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

int n, ans;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<>> pq;

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

    std::sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        while (!pq.empty()) {
            if (pq.top()>v[i].first){
                break;
            }
            pq.pop();
        }
        pq.push(v[i].second);
        ans = max(ans, (int) pq.size());
    }

    cout << ans;
}