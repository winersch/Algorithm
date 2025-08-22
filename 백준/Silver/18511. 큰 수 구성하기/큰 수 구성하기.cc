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

vi v;
int n, k, ans;

void dfs(long long x) {
    if (x > n) return;
    ans = max(ans, (int)x);

    for (int i = 0; i < k; i++) {
        dfs(x * 10 + v[i]);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int a; cin >> a;
        v.push_back(a);
    }
    std::sort(v.begin(), v.end(), greater());

    dfs(0);

    cout << ans;
    return 0;
}