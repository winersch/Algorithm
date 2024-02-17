#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>


#define inf 0x3f3f3f3f;
#define mod 1000000000;
using namespace std;

int n, ans;
int check[30];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        memset(check,0,sizeof(check));
        bool isGroup = true;
        string s;
        cin >> s;
        check[s[0]-'a']++;
        for (int j = 1; j < s.length(); j++) {
            if (s[j] != s[j-1]){
                if (check[s[j]-'a'] != 0){
                    isGroup = false;
                    break;
                }
            }
            check[s[j]-'a']++;
        }
        if (isGroup){
            ans++;
        }
    }

    cout << ans;
    return 0;
}
