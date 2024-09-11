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


int n;
int dp[31];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    dp[0] = 1;
    dp[2] = 3;

    for (int i = 4; i <= n; i++) {
        for (int j = 2; j <= i; j+=2) {
            if (j == 2){
                dp[i] += dp[i-j]*3;
            }else{
                dp[i] += dp[i-j]*2;
            }
        }
    }

    cout << dp[n];
    return 0;
}