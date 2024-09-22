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

int n, k, ans;
int arr[200001];
int cnt[100001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int left = 0;
    int right = 0;

    for (left = 0; left < n; left++) {
        while(right < n && cnt[arr[right]] < k){
            cnt[arr[right]]++;
            right++;
        }
        ans = max(ans, right - left);
        if (right == n){
            break;
        }
        cnt[arr[left]]--;
    }

    cout << ans;

    return 0;
}