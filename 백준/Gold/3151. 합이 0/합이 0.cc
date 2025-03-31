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

ll n, ans;
vi v, two;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    std::sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int tmp = v[i] + v[j];
            int cnt = upper_bound(v.begin(), v.end(), -tmp) - lower_bound(v.begin(), v.end(), -tmp);
            if (cnt == 0){
                continue;
            }
            if (v[i] == -tmp){
                cnt--;
            }
            if (v[j] == -tmp){
                cnt--;
            }
            ans += cnt;
        }
    }

    cout << ans/3;

}

