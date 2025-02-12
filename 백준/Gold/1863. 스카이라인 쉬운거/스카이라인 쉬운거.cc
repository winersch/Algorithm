#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <numeric>
#include <set>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n, ans;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    stack<int> st;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (st.empty()){
            st.push(b);
        }else{
            while(!st.empty() && st.top() > b){
                st.pop();
                ans++;
            }
            if (st.empty() || st.top() < b){
                st.push(b);
            }
        }
        if (st.top() == 0){
            st.pop();
        }
    }
    while(!st.empty()){
        st.pop();
        ans++;
    }
    cout << ans;

    return 0;
}

