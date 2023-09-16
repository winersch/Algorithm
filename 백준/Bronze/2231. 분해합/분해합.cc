#include <iostream>

using namespace std;


int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a;
        a = i + i % 10 + (i % 100) / 10 + (i % 1000) / 100 + (i % 10000) / 1000 + (i % 100000) / 10000 +
            (i % 1000000) / 100000 + (i % 10000000) / 1000000;
        if (a == n){
            cout << i;
            return 0;
        }
    }
    cout << 0;


    return 0;
}
