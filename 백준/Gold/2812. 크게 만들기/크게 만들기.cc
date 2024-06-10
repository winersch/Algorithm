#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>

using namespace std;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n,k;
    cin >> n >> k;
    stack<int> st;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        char a;
        cin.get(a);
        int x = a - '0';
        while(!st.empty() && x > st.top() && k > 0){
            st.pop();
            k--;
        }
        st.push(x);
    }
    while(k > 0){
        st.pop();
        k--;
    }

    stack<int> ans;
    while(!st.empty()){
        ans.push(st.top());
        st.pop();
    }

    while(!ans.empty()){
        cout << ans.top();
        ans.pop();
    }

    return 0;
}