#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>

#define inf 0x3f3f3f;
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 3; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        switch (a+b+c+d) {
            case 0:
                cout << "D\n";
                break;
            case 1:
                cout << "C\n";
                break;
            case 2:
                cout << "B\n";
                break;
            case 3:
                cout << "A\n";
                break;
            case 4:
                cout << "E\n";
                break;
        }
    }


    return 0;
}
