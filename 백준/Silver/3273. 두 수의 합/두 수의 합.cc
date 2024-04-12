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
#define mod 10007
#define ll long long
using namespace std;

int n, num, ans;
vector<int> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    std::sort(v.begin(), v.end());
    cin >> num;
    for (int i = 0; i < n; i++) {
        if (v[i] > num){
            break;
        }
        int t = num - v[i];
        ans += upper_bound(v.begin(), v.end(), t) - lower_bound(v.begin(), v.end(), t);
    }
    cout << ans/2;

    return 0;
}