#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

long long m = 1234567891;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int l;
    cin >> l;
    string s;
    cin >> s;
    long long hash = 0;
    long long r = 1;
    for (int i = 0; i < l; i++) {
        char a = s[i];
        hash = (hash + (a - 96) * r) % m;
        r = (r * 31) % m;
    }

    cout << hash;
    return 0;
}