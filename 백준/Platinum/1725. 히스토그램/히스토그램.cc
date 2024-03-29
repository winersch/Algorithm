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


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    stack<pair<int, int>> st;
    for (int i = 0; i <= n; i++) {
        int a = 0, idx = i;
        if (i != n){
            cin >> a;
        }
        while (!st.empty() && st.top().first > a) {
            idx = st.top().second;
            ans = max(ans, st.top().first * (i-idx));
            st.pop();
        }
        st.push({a, idx});
    }

    cout << ans;
}