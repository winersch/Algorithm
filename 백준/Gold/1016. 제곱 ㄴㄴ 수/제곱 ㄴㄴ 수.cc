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

bool num[1000001];
ll mx,mn;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> mn >> mx;

    ll cnt = mx - mn + 1;

    for (ll i = 2; i * i <= mx; i++) {
        ll ret = mn / (i*i);
        if (mn % (i*i) != 0){
            ret++;
        }

        while(ret * (i*i) <= mx){
            if (!num[ret * (i * i) - mn]){
                num[ret * (i*i)-mn] = true;
                cnt--;
            }
            ret++;
        }

    }
    cout << cnt;
    return 0;
}