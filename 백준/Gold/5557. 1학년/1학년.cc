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

int n;
int num[101];
ll dp[100][21];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    dp[0][num[0]] = 1;

    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j <= 20; j++) {
            if (dp[i-1][j]){
                if (j - num[i] >= 0){
                    dp[i][j-num[i]] += dp[i-1][j];
                }
                if (j + num[i] <= 20){
                    dp[i][j+num[i]] += dp[i-1][j];
                }
            }
        }
    }

    cout << dp[n-2][num[n-1]];

    return 0;
}