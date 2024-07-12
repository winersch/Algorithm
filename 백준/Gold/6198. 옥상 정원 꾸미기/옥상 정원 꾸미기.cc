#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>
#include <numeric>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>

using namespace std;

ll n, ans;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    stack<int> st;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (st.empty()){
            st.push(a);
        }else{
            while (!st.empty() && st.top() <= a){
                st.pop();
            }
            ans += st.size();
            st.push(a);
        }
    }

    cout << ans;

    return 0;
}