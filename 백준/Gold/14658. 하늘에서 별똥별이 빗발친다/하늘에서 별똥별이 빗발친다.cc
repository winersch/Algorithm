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

int n, m, l, k, ans;
vector<pii> v;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

int check(int y, int x){
    int cnt = 0;
    for(const auto&[a,b]: v){
        if (y <= a && a <= y+l && x <= b && b <= x+l){
            cnt++;
        }
    }
    return cnt;
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> l >> k;

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({b,a});
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            ans = max(ans, check(v[i].first, v[j].second));
        }
    }
    cout << k - ans;

    return 0;
}

