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

int n, ans;
vector<pii> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v.push_back({a*100 + b, c*100 + d});
    }

    std::sort(v.begin(), v.end());

    int curr = 301;
    int end = 301;
    int idx = 0;
    while(curr <= 1130){
        bool found = false;

        while(idx < n && v[idx].first <= curr){
            if (v[idx].second > end){
                end = v[idx].second;
                found = true;
            }
            idx++;
        }

        if (!found){
            cout << 0;
            return 0;
        }
        ans++;
        curr = end;
    }

    cout << ans;

    return 0;
}

