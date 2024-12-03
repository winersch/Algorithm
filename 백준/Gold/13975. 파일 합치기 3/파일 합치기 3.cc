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



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        priority_queue<ll,vector<ll>,greater<>> pq;
        for (int i = 0; i < n; i++) {
            ll a;
            cin >> a;
            pq.push(a);
        }
        ll ans = 0;
        while(!pq.empty() && pq.size() > 1){
            ll a = pq.top();
            pq.pop();
            ll b = pq.top();
            pq.pop();
            ans += a + b;
            pq.push(a+b);
        }
        cout << ans << "\n";
    }

    return 0;
}