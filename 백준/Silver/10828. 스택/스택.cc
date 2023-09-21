#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;


int main() {
    cin.tie(NULL);
//    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    stack<int> st;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s[0] == 'p' && s[1] == 'u') {
            int n;
            cin >> n;
            st.push(n);
        } else if (s[0] == 't') {
            if (st.empty()) {
                cout << -1 << "\n";
            } else {
                cout << st.top() << "\n";
            }
        } else if (s[1] == 'o') {
            if (st.empty()) {
                cout << -1 << "\n";
            } else {
                cout << st.top() << "\n";
                st.pop();
            }
        } else if (s[0] == 'e') {
            if (st.empty()) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else if (s[0] == 's') {
            cout << st.size() << "\n";
        }
    }


    return 0;
}