#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>
#include <map>
#include <numeric>
#include <cmath>


using namespace std;
long double ans;

double triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a = x1 * y2 + x2 * y3 + x3 * y1;
    a += -y1 * x2 - y2 * x3 - y3 * x1;
    return a / 2;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<double, double>> v;
    for (int i = 0; i < n; i++) {
        double a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    for (int i = 2; i < n; i++) {
        ans += triangle(v[0].first, v[0].second, v[i - 1].first, v[i - 1].second, v[i].first, v[i].second);
    }

    cout << fixed;
    cout.precision(1);
    cout << abs(ans);
    return 0;
}