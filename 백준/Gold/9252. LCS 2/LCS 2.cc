#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>
#include <map>
#include <numeric>
#include <cmath>


using namespace std;

int dp[1001][1001];
string st;
int a, b;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    string s1, s2;
    cin >> s1 >> s2;

    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    a = s1.length();
    b = s2.length();
    while (dp[a][b] > 0 && a > 0 && b > 0) {

        if (dp[a-1][b] == dp[a][b]){
            a--;
        }else if (dp[a][b-1] == dp[a][b]){
            b--;
        }else{
            a--;
            b--;
            st += s1[a];
        }
    }
    std::reverse(st.begin(), st.end());
    cout << dp[s1.length()][s2.length()] << "\n";
    if (dp[s1.length()][s2.length()] > 0) {
        cout << st;
    }
    return 0;
}