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
#include <set>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n, c;
map<int, int> m;
map<int, int> idx;

bool comp(pair<int, int> &a, pair<int, int> &b) {
    if (a.second == b.second)
        return idx[a.first] < idx[b.first];

    return a.second > b.second;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        m[a]++;
        if (!idx[a]) {
            idx[a] = i + 1;
        }
    }
    vector<pii > v(m.begin(), m.end());
    std::sort(v.begin(), v.end(), comp);
    for (pii p: v) {
        for (int i = 0; i < p.second; i++) {
            cout << p.first << " ";
        }
    }

}