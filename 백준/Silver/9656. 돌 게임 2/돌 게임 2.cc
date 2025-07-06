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

int n;
int dp[1001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 0;
    for (int i = 4; i <= n; i++) {
        if (dp[i-1] == 0 || dp[i-3] == 0){
            dp[i] = 1;
        }else{
            dp[i] = 0;
        }
    }
    if (dp[n] == 1){
        cout << "SK";
    }else{
        cout << "CY";
    }

    return 0;
}