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

int n, h, ansCnt = inf, ans;
int bottom[500001];
int top[500001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> h;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (i%2 == 0){
            bottom[a]++;
        }else{
            top[h-a+1]++;
        }
    }

    for (int i = 1; i <= h; i++) {
        top[i] += top[i-1];
    }
    for (int i = h-1; i > 0; i--) {
        bottom[i] += bottom[i+1];
    }

    for (int i = 1; i <= h; i++) {
        int cnt = top[i] + bottom[i];
        if (cnt < ansCnt){
            ansCnt = cnt;
            ans = 1;
        }else if(cnt == ansCnt){
            ans++;
        }
    }

    cout << ansCnt << " " << ans;
    return 0;
}