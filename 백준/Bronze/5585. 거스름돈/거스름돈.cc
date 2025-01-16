#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <numeric>
#include <set>


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

    int n;
    cin >> n;
    int ans = 0;
    n = 1000 - n;
    if (n >= 500){
        ans += n / 500;
        n %= 500;
    }
    if (n >= 100){
        ans += n / 100;
        n %= 100;
    }
    if (n >= 50){
        ans += n / 50;
        n %= 50;
    }
    if (n >= 10){
        ans += n / 10;
        n %= 10;
    }
    if (n >= 5){
        ans += n / 5;
        n %= 5;
    }
    ans += n;

    cout << ans;

    return 0;
}