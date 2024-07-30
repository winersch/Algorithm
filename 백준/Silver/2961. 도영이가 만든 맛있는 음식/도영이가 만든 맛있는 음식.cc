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

using namespace std;

int n, sour, bitter, ans = 2100000000;
int ing[11][2];

void find(int idx, int s, int b){
    ans = min(ans, abs(s-b));
    if (idx == n){
        return;
    }
    for (int i = idx; i < n; i++) {
        find(i+1, ing[i][0] * s, ing[i][1]+ b);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ing[i][0] >> ing[i][1];
    }

    for (int i = 0; i < n; i++) {
        find(i+1, ing[i][0], ing[i][1]);
    }

    cout << ans;
    return 0;
}