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

int n;
ll ans;
vector<int> v1, v2;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a > 0) {
            v1.push_back(a);
        } else {
            v2.push_back(a);
        }
    }

    std::sort(v1.begin(), v1.end(), greater<>());
    std::sort(v2.begin(), v2.end());

    if (v1.size() % 2 == 1) {
        ans += v1.back();
    }
    if (v2.size() % 2 == 1) {
        ans += v2.back();
    }

    for (int i = 0; i < v1.size() - 1; i += 2) {
        if (v1.size() < 1) {
            break;
        }
        if (v1[i + 1] == 1) {
            ans += v1[i] + v1[i + 1];
        } else {
            ans += v1[i] * v1[i + 1];
        }
    }
    for (int i = 0; i < v2.size() - 1; i += 2) {
        if (v2.size() < 1) {
            break;
        }
        ans += v2[i] * v2[i + 1];
    }

    cout << ans;
    return 0;
}