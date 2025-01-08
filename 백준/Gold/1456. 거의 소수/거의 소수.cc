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

bool is_prime[10000001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    ll a, b;
    cin >> a >> b;
    memset(is_prime, true, sizeof(is_prime));

    for (int i = 2; i*i <= 10000001; i++) {
        if (is_prime[i]){
            for (int j = i*i; j < 10000001; j+=i) {
                is_prime[j] = false;
            }
        }
    }

    ll ans = 0;
    for (int i = 2; i < 10000001; i++) {
        if (is_prime[i]){
            ll t = i;
            while(t <= b / i){
                t *= i;
                if (a <= t){
                    ans++;
                }
            }
        }
    }

    cout << ans;


    return 0;
}