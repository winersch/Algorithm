#include <iostream>

using namespace std;

int main() {
    int a, b, sum = 0, count = 0;
    cin >> a >> b;

    for (int i = 1; i <= b; i++) {
        for (int j = 1; j <= i; j++) {
            count++;
            if (count >= a && count <= b) {
                sum += i;
            }
        }
    }
    cout << sum;
    return 0;
}
