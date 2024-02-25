#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int a, b, c, t;
    cin >> a >> b >> c >> t;
    c += t;
    b += c/60;
    c %= 60;
    a += b/60;
    b %= 60;
    a %= 24;
    cout << a << " " << b << " " << c;
    return 0;
}
