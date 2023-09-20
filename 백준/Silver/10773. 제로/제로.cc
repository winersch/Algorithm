#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


int main() {
    int n, result = 0;
    cin >> n;
    stack<int> st;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a != 0){
            st.push(a);
        } else{
            st.pop();
        }
    }

    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    cout << result;
    return 0;
}

