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
#define vi vector<int>

using namespace std;


ll cnt[10];

void count(int n, int t){
    while(n){
        cnt[n%10] += t;
        n /= 10;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int s, e;
    cin >> s >> e;
    int base = 1;
    while(s <= e){
        while(s % 10 != 0 && s <= e){
            count(s, base);
            s++;
        }
        if (s > e){
            break;
        }

        while(e %10 != 9 && s <= e){
            count(e, base);
            e--;
        }
        s /= 10;
        e /= 10;

        if (s==0 && e==0){
            break;
        }

        for (int i = 0; i < 10; i++) {
            cnt[i] += (e-s+1)*base;
        }
        base *= 10;
    }

    ll ans = 0;
    for (int i = 1; i < 10; i++) {
        ans += i*cnt[i];
    }

    cout << ans;
    return 0;
}