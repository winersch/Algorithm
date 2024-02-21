#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>


#define inf 0x3f3f3f3f
#define mod 1000000007
#define ll long long
using namespace std;

int d;
vector<vector<ll>> v = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1, 0},
        {0, 0, 0, 1, 1, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 1, 0}
};
//정보	전산	미래	신양	한경직	진리	형남	학생회

vector<vector<ll>> mul(vector<vector<ll>> &v1, vector<vector<ll>> &v2) {

    vector<vector<ll>> result(8, vector<ll>(8));

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                result[i][j] += v1[i][k] * v2[k][j];
            }
            result[i][j] %= mod;
        }
    }

    return result;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> d;

    vector<vector<ll>> ans(8, vector<ll>(8));
    for (int i = 0; i < 8; i++) {
        ans[i][i] = 1;
    }
    while (d > 0) {
        if (d & 1) {
            ans = mul(ans, v);
            d--;
        }
        v = mul(v, v);
        d /= 2;
    }

    cout << ans[0][0];
    return 0;
}
