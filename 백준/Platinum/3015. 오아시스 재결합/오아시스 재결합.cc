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
#define mod 1234567
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>

using namespace std;

ll n, ans;
stack<pii > st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ll cnt = 1;
        while (!st.empty() && st.top().first <= a) {
            ans += st.top().second;
            if (st.top().first == a){
                cnt += st.top().second;
            }
            st.pop();
        }
        if (!st.empty()){
            ans++;
        }
        st.push({a, cnt});
    }


    cout << ans;


    return 0;
}