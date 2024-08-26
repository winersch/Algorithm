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
#define vi vector<int>

using namespace std;

int ans[3];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    if (t % 10 != 0){
        cout << -1;
        return 0;
    }

    if (t / 300 > 0){
        ans[0] = t / 300;
        t %= 300;
    }
    if (t / 60 > 0){
        ans[1] = t / 60;
        t %= 60;
    }
    if (t/10 > 0){
        ans[2] = t/10;
    }

    for (int i = 0; i < 3; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}