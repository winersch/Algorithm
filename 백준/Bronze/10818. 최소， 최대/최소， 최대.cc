#include <iostream>

using namespace std;


int main() {
    int n, ma = -1000001, mi = 1000001;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        mi = min(a, mi);
        ma = max(a, ma);
    }
    cout << mi << " " << ma;
    return 0;
}