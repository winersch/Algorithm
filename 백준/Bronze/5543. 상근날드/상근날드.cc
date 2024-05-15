#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    a = min(a+d-50, a+e-50);
    b = min(b+d-50, b+e-50);
    c = min(c+d-50, c+e-50);

    cout << min(a, min(b,c));


    return 0;
}