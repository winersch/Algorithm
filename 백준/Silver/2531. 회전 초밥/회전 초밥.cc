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

int n, d, k, c, ans;
int arr[30001];
bool check[3001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> d >> k >> c;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        memset(check, false, sizeof(check));
        int cnt = 0, coupon = 1;
        for (int j = i; j < i + k; j++) {
            if (!check[arr[j%n]]){
                check[arr[j%n]] = true;
            }else{
                cnt++;
            }
        }
        if (check[c]){
            coupon--;
        }
        ans = max(ans, k - cnt + coupon);
    }
    cout << ans;
    return 0;
}