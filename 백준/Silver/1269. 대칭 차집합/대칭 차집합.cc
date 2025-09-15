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
#include <regex>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>
#define vs vector<string>

using namespace std;



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    set<int> a, b;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        b.insert(x);
    }
    int ans = 0;
    for (auto at : a) {
        if (b.find(at) == b.end()){
            ans++;
        }
    }
    for (auto at : b) {
        if (a.find(at) == a.end()){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
