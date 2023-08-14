#include <iostream>

using namespace std;

int main() {
    int a[4], b[4], sum1 = 0, sum2 = 0;

    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < 4; i++) {
        sum1 += a[i];
        sum2 += b[i];
    }
    
    if (sum1 >= sum2) {
        cout << sum1;
    } else {
        cout << sum2;
    }

    return 0;
}
