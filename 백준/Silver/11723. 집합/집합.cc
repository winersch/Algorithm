#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>


using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int m, a;
    cin >> m;
    int bit = 0;

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (s == "add") {
            cin >> a;
            bit |= (1 << a);
        } else if (s == "remove") {
            cin >> a;
            bit &= ~(1 << a);
        } else if (s == "check") {
            cin >> a;
            if (bit & (1 << a)) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else if (s == "toggle") {
            cin >> a;
            bit ^= (1 << a);
        } else if (s == "all") {
            bit |= (1 << 21) - 1;
        } else if (s == "empty") {
            bit = 0;
        }


    }


    return 0;
}