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
#include <set>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n, m, ans;
vi v1,v2;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a < 0){
            v1.push_back(-a);
        }else{
            v2.push_back(a);
        }
    }

    sort(v1.begin(), v1.end(), greater<>());
    sort(v2.begin(), v2.end(), greater<>());

    for (int i = 0; i < v1.size(); i+=m) {
        ans += v1[i]*2;
    }
    for (int i = 0; i < v2.size(); i+=m) {
        ans += v2[i]*2;
    }

    if (!v1.empty() && !v2.empty()){
        ans -= max(v1[0], v2[0]);
    }else if(v1.empty()){
        ans -= v2[0];
    }else{
        ans -= v1[0];
    }

    cout << ans;

    return 0;
}