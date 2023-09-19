#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


int main() {

    while (true) {
        int isyes = 1;
        string s;
        getline(cin, s);
        if (s[0] == '.' && s.length() == 1) {
            break;
        }
        stack<char> st;

        for (char a: s) {
            if (a == '(') {
                st.push('(');
            } else if (a == ')') {
                if (st.empty()) {
                    isyes = 0;
                    break;
                } else if (st.top() != '(') {
                    isyes = 0;
                    break;
                } else {
                    st.pop();
                }
            }
            if (a == '[') {
                st.push('[');
            } else if (a == ']') {
                if (st.empty()) {
                    isyes = 0;
                    break;
                } else if (st.top() != '[') {
                    isyes = 0;
                    break;
                } else {
                    st.pop();
                }
            }
        }
        if (isyes && st.empty() && s[s.length() - 1] == '.') {
            cout << "yes" << "\n";
        } else {
            cout << "no" << "\n";
        }

    }

    return 0;
}

