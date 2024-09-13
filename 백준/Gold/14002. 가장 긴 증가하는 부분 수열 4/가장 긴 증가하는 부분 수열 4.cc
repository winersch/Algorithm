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

int n, cnt, idx;
int arr[1001];
int dp[1001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        if(dp[i] > cnt){
            idx = i;
            cnt = dp[i];
        }
    }
    int tmp = cnt;
    vi ans;
    ans.push_back(arr[idx]);
    for (int i = idx-1; i >= 0; i--) {
        if (dp[i] == tmp-1){
            tmp--;
            ans.push_back(arr[i]);
        }
    }
    std::reverse(ans.begin(), ans.end());

    cout << cnt << "\n";
    for(int a : ans){
        cout << a << " ";
    }
    return 0;
}