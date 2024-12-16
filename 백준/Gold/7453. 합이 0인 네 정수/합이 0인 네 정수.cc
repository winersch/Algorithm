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
int arr[4001][4];
vi l, r;



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            l.push_back(arr[i][0] + arr[j][1]);
            r.push_back(arr[i][2] + arr[j][3]);
        }
    }

    std::sort(l.begin(), l.end());
    std::sort(r.begin(), r.end());
    for (int i = 0; i < l.size(); i++) {
        auto a = lower_bound(r.begin(), r.end(),-l[i]);
        auto b = upper_bound(r.begin(), r.end(), -l[i]);
        if (b-a > 0){
            ans += b-a;
        }
    }

    cout << ans;
    return 0;
}