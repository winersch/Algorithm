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
#include <sstream>
#include <ctime>
#include <iomanip>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>
#define vs vector<string>

using namespace std;

int n;
vi v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<tuple<int, int, int>> pairs;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            pairs.push_back({v[i] + v[j], i, j});
        }
    }
    std::sort(pairs.begin(), pairs.end());

    int ans = inf;
    int m = pairs.size();

    for (int i = 0; i < m; ++i) {
        auto [sum1, a1, b1] = pairs[i];
        for (int j = i + 1; j < m; ++j) {
            auto [sum2, a2, b2] = pairs[j];
            if (a1 != a2 && a1 != b2 && b1 != a2 && b1 != b2) {
                ans = min(ans, abs(sum1 - sum2));
                break;
            }
        }
    }

    cout << ans;

    return 0;
}