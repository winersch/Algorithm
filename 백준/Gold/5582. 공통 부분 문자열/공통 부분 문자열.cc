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

int dp[4001][4001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    string s1, s2;
    cin >> s1 >> s2;
    int ans = 0;
    for (int i = 0; i < s1.length(); i++) {
        for (int j = 0; j < s2.length(); j++) {
            if (s1[i] == s2[j]){
                dp[i][j] = 1;
                if (i > 0 && j > 0){
                    dp[i][j] += dp[i-1][j-1];
                }
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans;


    return 0;
}