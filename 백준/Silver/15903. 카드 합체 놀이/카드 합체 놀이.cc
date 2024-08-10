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
#define vi vector<int>

using namespace std;

int n,m;
ll ans;
priority_queue<ll, vector<ll>, greater<>> pq;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        pq.push(a);
    }

    while(m--){
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();
        pq.push(a+b);
        pq.push(a+b);
    }

    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
    }

    cout << ans;

    return 0;
}