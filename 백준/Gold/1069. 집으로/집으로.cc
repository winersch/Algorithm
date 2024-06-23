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

double x, y, d, t;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> x >> y >> d >> t;
    double ans = inf;
    double a = sqrt(x * x + y * y);
    ans = min(ans, a);

    for (int i = 1;; i++) {
        if (i == 1) {
            a = abs(d - a);
            ans = min(ans, a + t * i);
        } else {
            a = a - d;
            if (a <= 0) {
                ans = min(ans, t * i);
                break;
            }
            ans = min(ans, abs(a) + t * i);
        }
    }
    cout << fixed;
    cout.precision(9);
    cout << ans;

    return 0;
}