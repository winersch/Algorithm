#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>


using namespace std;


string s;
// + - * / ()

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> s;
    stack<char> st;
    queue<char> q;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            q.push(s[i]);
            continue;
        }
        if (s[i] == '(') {
            st.push(s[i]);
        } else if (st.empty()) {
            st.push(s[i]);
        } else {
            if (s[i] == ')') {
                char ch = st.top();
                st.pop();
                while (ch != '(') {
                    q.push(ch);
                    ch = st.top();
                    st.pop();
                }
            }
            if (s[i] == '*' || s[i] == '/') {
                if (st.top() == '+' || st.top() == '-'){
                    st.push(s[i]);
                }else if (st.top() == '*' || st.top() == '/'){
                    while (!st.empty()){
                        if (st.top() == '(' || st.top() =='+' || st.top() == '-'){
                            break;
                        }
                        q.push(st.top());
                        st.pop();
                    }
                    st.push(s[i]);
                } else if (st.top() == '('){
                    st.push(s[i]);
                }

            }
            if (s[i] == '+' || s[i] == '-'){
                while (!st.empty()){
                    if (st.top() == '('){
                        break;
                    }
                    q.push(st.top());
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }

    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }
    while (!q.empty()) {
        cout << q.front();
        q.pop();
    }

    return 0;
}