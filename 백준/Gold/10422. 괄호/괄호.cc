#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

#define inf 0x3f3f3f
#define pii pair<int,int>
#define ll long long

ll dp[5001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    dp[0] = 1;

    for (int i = 2; i <= 5000; i+=2) {
        for (int j = 2; j <= i; j+=2) {
            dp[i] += dp[j-2] * dp[i-j];
            dp[i]%=1000000007;
        }
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        cout << dp[n] << "\n";

    }



    return 0;
}