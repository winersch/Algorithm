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

int n, ans;
int arr[51];
int cnt[51];

bool ccw(pii p1, pii p2, pii p3){
    int cross = (p2.second - p1.second) * (p3.first - p1.first) - (p2.first - p1.first) * (p3.second - p1.second);
    return cross > 0;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        double max_lev = -inf;
        for (int j = i+1; j < n; j++) {
            double lev = (double)(arr[j] - arr[i]) / (j - i);
            if (lev > max_lev){
                cnt[i]++;
                cnt[j]++;
                max_lev = lev;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        ans = max(ans, cnt[i]);
    }
    cout << ans;
    return 0;
}

