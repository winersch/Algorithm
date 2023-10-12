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
    string s, p = "";
    cin >> s;
    vector<int> cnt;
    for (int i = 2; i < m; i++) {
        if (s[i] == 'I') {
            if (s[i - 1] == 'O') {
                if (s[i - 2] == 'I') {
                    p += "1";
                } else {
                    p += s[i];
                }
            } else {
                p += s[i];
            }
        }
    }

    for (int i = 0; i < p.length(); i++) {
        int c = 0;
        while (i < p.length() && p[i] == '1') {
            i++;
            c++;
        }
        cnt.push_back(c);
    }
    for (int i = 0; i < cnt.size(); i++) {
        if (n <= cnt[i]) {
            count += cnt[i] - n + 1;
        }
    }
    cout << count;
    return 0;
}