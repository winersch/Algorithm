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



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    stack<char> st;
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '('){
            st.push(s[i]);
        }else{
            if (s[i-1] == '('){
                st.pop();
                ans += st.size();
            }else{
                st.pop();
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}