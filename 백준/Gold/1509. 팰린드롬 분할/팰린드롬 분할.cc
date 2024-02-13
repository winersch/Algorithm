#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>

#define inf 0x3f3f3f3f;
using namespace std;

bool palindrom[2501][2501];
int dp[2501];
string s;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        palindrom[i][i] = true;
    }
    s = " " + s;

    for (int i = 1; i < s.length(); i++) {
        for (int j = 1; j < s.length(); j++) {

            if (s[i] == s[j]){
                int t1 = min(i,j);
                int t2 = max(i,j);
                bool isPalindrom = true;
                while(t1 <= t2){

                    if (s[t1] != s[t2]){
                        isPalindrom = false;
                        break;
                    }else if(palindrom[t1][t2]){
                        break;
                    }else{
                        t1++;
                        t2--;
                    }
                }
                if (isPalindrom){
                    palindrom[i][j] = true;
                }
            }
        }
    }
    for (int i = 1; i < s.length(); i++) {
        dp[i] = inf;
        for (int j = 1; j <= i; j++) {
            if (palindrom[i][j]){
                dp[i] = min(dp[i], dp[j-1]+1);
            }
        }
    }
    cout << dp[s.length()-1];
    return 0;
}
