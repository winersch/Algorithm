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
#include <sstream>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n, k, ans;
map<string, bool> m;
vi v;
bool selected[11];

void solve(int cnt, string st){
    if (cnt == k){
        if (m[st] == false){
            m[st] = true;
            ans++;
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!selected[i]){
            selected[i] = true;
            solve(cnt+1, st + to_string(v[i]));
            selected[i] = false;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    solve(0,"");


    cout << ans;

    return 0;
}
