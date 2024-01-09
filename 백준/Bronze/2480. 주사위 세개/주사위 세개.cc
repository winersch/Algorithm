#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && a == c) {
        cout << 10000 + a * 1000;
    } else if (a == b || a == c) {
        cout << 1000 + a * 100;
    } else if (b == c) {
        cout << 1000 + b * 100;
    }else{
        cout << max(a, max(b,c))*100;
    }


    return 0;
}