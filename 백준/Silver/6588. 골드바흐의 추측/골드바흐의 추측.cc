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

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

bool is_prime[1000001];
vi prime;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    memset(is_prime, true, sizeof(is_prime));

    for (int i = 2; i*i <= 1000000; i++) {
        if (is_prime[i]){
            for (int j = i+i; j <= 1000000; j+=i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 3; i <= 1000000; i++) {
        if (is_prime[i]){
            prime.push_back(i);
        }
    }

    while(true){
        int n;
        cin >> n;
        if (n == 0){
            break;
        }
        bool find = false;
        for(int a : prime){
            if (binary_search(prime.begin(), prime.end(), n - a)){
                find = true;
                cout << n << " = " << a << " + " << n-a << "\n";
                break;
            }
        }
        if (!find){
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }
}

