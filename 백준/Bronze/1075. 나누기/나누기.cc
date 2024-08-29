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


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, ans = 0;
    cin >> n >> m;
    n = (n/100)*100;
    while(true){
        if (n%m == 0){
            break;
        }
        ans++;
        n++;
    }

    if (ans < 10){
        cout << 0;
    }
    cout << ans;

    return 0;
}