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
#define mod 10007
#define ll long long
using namespace std;



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while(t > 0){
        int n, m, cnt = 0;
        cin >> n >> m;
        for (int i = n; i <= m; i++) {
            string s = to_string(i);
            for (int j = 0; j < s.length(); j++) {
                if (s[j] == '0'){
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";

        t--;
    }


    return 0;
}