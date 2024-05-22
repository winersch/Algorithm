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

vector<pii> v;
int n, ans;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    std::sort(v.begin(), v.end());
    ans += v[0].second - v[0].first;
    int tmp = v[0].second;
    for (int i = 1; i < n; i++) {
        if (v[i].first >= tmp){
            ans += v[i].second - v[i].first;
            tmp = v[i].second;
        }else{
            if (v[i].second <= tmp){
                continue;
            }else{
                ans += v[i].second - tmp;
                tmp = v[i].second;
            }
        }
    }
    cout << ans;

    return 0;
}