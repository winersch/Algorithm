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
#include <list>
#include <unordered_set>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n;
int arr[100001];
int cnt[100001];
int near[100001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    stack<pii> st;
    memset(near, -inf, sizeof(near));
    for (int i = 1; i <= n; i++) {
        while(!st.empty() && st.top().first <= arr[i]){
            st.pop();
        }
        if (st.empty()){
            st.push({arr[i], i});
            continue;
        }
        cnt[i] += st.size();
        near[i] = st.top().second;
        st.push({arr[i], i});
    }
    while(!st.empty()){
        st.pop();
    }

    for (int i = n; i > 0; i--) {
        while(!st.empty() && st.top().first <= arr[i]){
            st.pop();
        }
        if (st.empty()){
            st.push({arr[i], i});
            continue;
        }
        cnt[i] += st.size();
        if (i - near[i] > st.top().second - i){
            near[i] = st.top().second;
        }
        st.push({arr[i], i});
    }

    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 0){
            cout << 0 << "\n";
        }else{
            cout << cnt[i] << " " << near[i] << "\n";
        }
    }

    return 0;
}

