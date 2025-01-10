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

ll n;
ll dist[100001];
ll cost[100001];


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> dist[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    ll m = inf;
    ll s = 0;

    for (int i = 0; i < n; i++) {
        if (cost[i] < m){
            m = cost[i];
        }
        s += m * dist[i+1];
    }

    cout << s;

    return 0;
}