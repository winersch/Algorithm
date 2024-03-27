#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>


#define inf 0x3f3f3f3f
#define mod 10007
#define ll long long
using namespace std;

map<string, int> m;
int n, ans;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s=="ENTER"){
            m.clear();
        }else{
            if (m[s] == 0){
                ans++;
                m[s]++;
            }
        }

    }
    cout << ans;
    return 0;
}