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
#define mod 10007
#define ll long long
using namespace std;

int n, ans;

bool check(string s){

    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (st.empty()){
            st.push(s[i]);
        }else{
            if (st.top() != s[i]){
                st.push(s[i]);
            }else{
                st.pop();
            }
        }
    }
    if (st.empty()){
        return true;
    }
    return false;
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (check(s)){
            ans++;
        }
    }
    cout << ans;

    return 0;
}