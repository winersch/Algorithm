#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    int exclude;
    int sum = 0;
    vector<int> v;
    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    exclude = floor(n * 0.15 + 0.5);

    sort(v.begin(), v.end());

    for (int i = exclude; i < n - exclude; i++) {
        sum += v[i];
    }
    n = n - exclude * 2;

    cout << floor((double)sum / n + 0.5);
    return 0;
}