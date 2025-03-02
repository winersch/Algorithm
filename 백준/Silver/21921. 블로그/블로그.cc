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

int n, x, ans, cnt;
vi v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int sum = 0;
    for (int i = 0; i < x; i++) {
        sum += v[i];
    }
    ans = sum;
    cnt = 1;
    for (int i = x; i < n; i++) {
        sum -= v[i-x];
        sum += v[i];
        if (sum > ans){
            cnt = 1;
            ans = sum;
        } else if (ans == sum){
            cnt++;
        }
    }
    if (ans == 0){
        cout << "SAD";
    }else{
        cout << ans << "\n" << cnt;
    }

    return 0;
}

