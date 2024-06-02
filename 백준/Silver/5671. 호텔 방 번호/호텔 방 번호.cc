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




int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int a, b, ans;
    bool x;
    while (cin >> a){
        cin >> b;
        ans = 0;
        for (int i = a; i <= b; i++) {
            string s = to_string(i);
            x = true;
            for (int j = 0; j < s.length(); j++) {
                for (int k = j+1; k < s.length(); k++) {
                    if (s[j] == s[k]){
                        x = false;
                        break;
                    }
                }
            }
            if (x){
                ans++;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}