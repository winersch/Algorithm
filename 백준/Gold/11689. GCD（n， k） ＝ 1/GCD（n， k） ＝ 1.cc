#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>


#define inf 0x3f3f3f3f
#define mod 1000000007
#define ll long long
using namespace std;

vector<ll> primes;

void sieve(){
    ll n = 1000000;
    vector<bool> isPrime(n+1, true);

    for (ll p = 2; p * p <= n; p++) {
        if (isPrime[p]){
            for (int i = p*p; i <= n ; i+=p) {
                isPrime[i] = false;
            }
        }
    }
    for (int p = 2; p <= n; p++) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }

}

ll eulerPhi(ll n) {
    ll result = n;

    for(ll p : primes){
        if (p*p > n){
            break;
        }
        if (n%p == 0){
            while(n%p == 0){
                n/=p;
            }
            result -= result/p;
        }
    }

    if (n > 1){
        result -= result/n;
    }
    return result;
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    sieve();
    cout << eulerPhi(n);

}