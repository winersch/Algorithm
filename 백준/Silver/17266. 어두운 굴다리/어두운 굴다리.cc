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

int n, m;
vi v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    int mgap = 0;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    for (int i = 0; i < m; i++) {
        if (i == 0){
            mgap = max(mgap, v[0]);
        }else{
            mgap = max(mgap, (v[i] - v[i-1] + 1) /2);
        }
        if (i == m-1){
            mgap = max(mgap, n - v[i]);
        }
    }
    cout << mgap;
    return 0;
}

