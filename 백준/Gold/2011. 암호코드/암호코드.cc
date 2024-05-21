#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>

using namespace std;
const int mod = 1000000;


string s;
int dp[5001];
int arr[5001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> s;
    dp[0] = 1;
    for (int i = 1; i <= s.length(); i++) {
        arr[i] = s[i-1] - '0';
    }

    if (s.length() == 1 && arr[1] == 0){
        cout << 0;
        return 0;
    }

    for (int i = 1; i <= s.length(); i++) {
        if (arr[i] > 0) {
            dp[i] = dp[i - 1] + dp[i];
            dp[i] %= mod;
        }
        if (i == 1) {
            continue;
        }
        int t = arr[i] + arr[i - 1] * 10;
        if (t >= 10 && t <= 26) {
            dp[i] = dp[i - 2] + dp[i];
            dp[i] %= mod;
        }

    }

    cout << dp[s.length()];

    return 0;
}