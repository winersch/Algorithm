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

int n, ans;
int c[53][53];


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;


    for (int i = 0; i < 53; i++) {
        c[i][0] = 1;
        c[i][i] = 1;
        for (int j = 1; j < i; j++) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            c[i][j] %= mod;
            c[i][i - j] = c[i][j];
        }
    }

    for (int i = 4; i <= n; i += 4) {
        if (i / 4 % 2 == 1) {
            ans += c[13][i / 4] * c[52 - i][n - i];
        } else {
            ans -= c[13][i / 4] * c[52 - i][n - i];
        }
        ans %= mod;
    }
    if (ans < 0){
        ans += mod;
    }
    cout << ans;
}