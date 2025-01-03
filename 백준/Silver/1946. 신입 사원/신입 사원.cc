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


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pii> v;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            v.push_back({a,b});
        }

        std::sort(v.begin(), v.end());

        int ans = 1;
        int idx = 0;

        for (int i = 1; i < n; i++) {
            if (v[idx].second > v[i].second){
                ans++;
                idx = i;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}