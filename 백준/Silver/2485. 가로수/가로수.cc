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
vi v, diff;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    for (int i = 0; i < v.size()-1; i++) {
        diff.push_back(v[i+1]-v[i]);
    }
    int num = accumulate(diff.begin(), diff.end(), diff[0], [](int a, int b){
        return gcd(a,b);
    });
    int ans = 0;
    for (int i = 0; i < diff.size(); i++) {
        ans += (diff[i]/num)-1;
    }

    cout << ans;

    return 0;
}

