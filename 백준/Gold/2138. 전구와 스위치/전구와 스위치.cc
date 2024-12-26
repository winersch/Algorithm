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

int n, ans = inf;
vi v1, v2;

int solve(int flag){
    vi v = v1;
    int cnt = 0;
    if (flag == 1){
        v[0] = !v[0];
        v[1] = !v[1];
        cnt++;
    }

    for (int i = 1; i < n; i++) {
        if (v[i-1] != v2[i-1]){
            cnt++;
            v[i-1] = !v[i-1];
            v[i] = !v[i];
            if (i != n-1){
                v[i+1] = !v[i+1];
            }
        }
    }
    if (v != v2){
        cnt = inf;
    }
    return cnt;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        v1.push_back(s[i]-'0');
    }
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        v2.push_back(s[i]-'0');
    }

    ans = solve(0);
    ans = min(ans, solve(1));
    if (ans == inf){
        ans = -1;
    }
    cout << ans;

    return 0;
}