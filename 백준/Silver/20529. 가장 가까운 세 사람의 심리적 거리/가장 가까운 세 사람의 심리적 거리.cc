#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>


using namespace std;

int calc(string a, string b) {
    int dist = 0;
    for (int i = 0; i < 4; i++) {
        if (a[i] != b[i]) {
            dist++;
        }
    }
    return dist;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        vector<string> v;
        for (int j = 0; j < a; j++) {
            string s;
            cin >> s;
            v.push_back(s);
        }
        if (a > 32) {
            cout << 0 << "\n";
        } else {
            int mn = 10000000;
            for (int j = 0; j < a - 2; j++) {
                for (int k = j + 1; k < a - 1; k++) {
                    for (int l = k + 1; l < a; l++) {
                        mn = min(mn, calc(v[j], v[k]) + calc(v[j], v[l]) + calc(v[k], v[l]));
                    }
                }
            }
            cout << mn << "\n";
        }
    }


    return 0;
}