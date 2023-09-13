#include <iostream>
#include <vector>
#include <stack>


using namespace std;


int main() {
    int n, max = 1;
    stack<int> st;
    vector<char> history;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        while (max <= a){
            st.push(max);
            max++;
            history.push_back('+');
        }
        if (st.top() == a){
            st.pop();
            history.push_back('-');
        } else{
            cout << "NO";
            return 0;
        }
    }
    for (int i = 0; i < history.size(); i++) {
        cout << history[i] << "\n";
    }

    return 0;
}