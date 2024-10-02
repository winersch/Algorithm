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

int n, ans;
int arr[100001];
int sum[100001];


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i];
    }


    for (int i = 2; i < n; i++) {
        int tmp = (sum[i] - sum[1]) + (sum[n-1] - sum[i-1]);
        ans = max(ans, tmp);
    }

    for (int i = 2; i < n; i++) {
        int tmp = (sum[n] - sum[1] - arr[i]) + (sum[n] - sum[i]);
        ans = max(ans, tmp);
    }

    for (int i = 2; i < n; i++) {
        int tmp = (sum[n-1] - arr[i]) + sum[i-1];
        ans = max(ans, tmp);
    }

    cout << ans;

    return 0;
}