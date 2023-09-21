#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;


int main() {
    cin.tie(NULL);
//    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s[0] == 'p' && s[1] == 'u') {
            int n;
            cin >> n;
            q.push(n);
        } else if (s[0] == 'f') {
            if (q.empty()) {
                cout << -1 << "\n";
            } else {
                cout << q.front() << "\n";
            }
        }  else if (s[0] == 'b') {
            if (q.empty()) {
                cout << -1 << "\n";
            } else {
                cout << q.back() << "\n";
            }
        } else if (s[1] == 'o') {
            if (q.empty()) {
                cout << -1 << "\n";
            } else {
                cout << q.front() << "\n";
                q.pop();
            }
        } else if (s[0] == 'e') {
            if (q.empty()) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else if (s[0] == 's') {
            cout << q.size() << "\n";
        }
    }


    return 0;
}