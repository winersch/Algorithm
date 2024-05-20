#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>

using namespace std;

int n, k, ans;
vector<int> v;
vector<int> dist;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n-1; i++) {
        dist.push_back(v[i+1] - v[i]);
    }
    sort(dist.begin(), dist.end(), greater<>());

    for (int i = k-1; i < n-1; i++) {
        ans += dist[i];
    }
    cout << ans;


    return 0;
}