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



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int j = 0; j < n; j++) {
            cin >> v[j];
        }
        std::sort(v.begin(), v.end());

        int ans = 0;
        ans = max(ans, v[1] - v[0]);
        ans = max(ans, v[n-1] - v[n-2]);

        for (int j = 0; j < n-2; j++) {
            ans = max(ans, v[j+2] - v[j]);
        }
        cout << ans << "\n";
    }

}