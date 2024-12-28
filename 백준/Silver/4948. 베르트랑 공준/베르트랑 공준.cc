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

int dp[300000];
bool is_prime[300000];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    memset(is_prime, true, sizeof(is_prime));

    int n;
    is_prime[0] = false;
    for (int i = 2; i < sqrt(250000); i++) {
        for (int j = i*2; j <= 250000; j += i) {
            is_prime[j] = false;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= 250000; i++) {
        if (is_prime[i]){
            cnt++;
        }
        dp[i] = cnt;
    }

    while (cin >> n) {
        if (n == 0) {
            break;
        }
        cout << dp[n*2] - dp[n] << "\n";

    }


    return 0;
}