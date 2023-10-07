#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <map>

using namespace std;



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, k, sum = 0;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    for (int i = n-1 ; i >= 0; i--) {
        sum += k/v[i];
        k %= v[i];
    }
    cout << sum;

    return 0;

}