#include <iostream>

int main() {
    using namespace std;

    int a, b, c, d, sum;

    cin >> a >> b >> c >> d;
    sum = a + b + c + d;
    cout << sum/60 << endl;
    cout << sum%60 << endl;
    return 0;
}
