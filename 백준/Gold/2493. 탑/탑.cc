#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

int n;
int tower[500001];


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    stack<int> st;

    for(int i = 1; i <= n; i++){
        cin >> tower[i];
        while(!st.empty() && tower[st.top()] < tower[i]){
            st.pop();
        }
        if (!st.empty()){
            cout << st.top() << " ";
        }else{
            cout << 0 << " ";
        }
        st.push(i);
    }


    return 0;
}