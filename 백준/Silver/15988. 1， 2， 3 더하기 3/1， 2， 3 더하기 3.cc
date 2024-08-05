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

ll dp[1000001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    int t;
    cin >> t;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= 1000000; i++) {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % 1000000009;
    }

    while(t--){
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }

    return 0;
}