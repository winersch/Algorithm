#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>
#include <map>


using namespace std;
map<long long, long long> m;
long long mod = 1000000007;
//a2n = an(an+1 + an-1)
long long doganu(long long n){

    if(n <= 0){
        return 0;
    }
    else if (n == 1){
        m[1] = 1;
        return 1;
    }else if(n == 2){
        m[2]= 1;
        return 1;
    }else if (m.count(n) > 0){
        return m[n];
    } else{
        if (n%2 == 0){
            long long a = doganu(n/2 - 1);
            long long b = doganu(n/2);
            m[n] = (2*a+b)%mod * b %mod;
            return m[n];
        } else{
            long long a = doganu(n/2 + 1);
            long long b = doganu(n/2);
            m[n] = (a*a) % mod + (b*b)%mod;
            return m[n];
        }
    }

}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    long long n;
    cin >> n;
    cout << doganu(n)%mod;


    return 0;
}