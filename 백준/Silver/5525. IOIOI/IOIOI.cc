#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>


using namespace std;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, count = 0;
    cin >> n >> m;
    string s, p;
    cin >> s;
    p = "IOI";
    for (int i = 1; i < n; i++) {
        p += "OI";
    }
    ssize_t found;
    while ((found = s.find(p)) != string::npos) {
        count++;
        s = s.substr(found+2);
    }
    cout << count;
    return 0;
}