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

ll n, ans;
int visited[100001];
int arr[100001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ans = n * (n + 1) / 2;

    ll left = 0, right = 1;
    visited[arr[left]] = true;
    while (right < n) {
        if (visited[arr[right]]){
            visited[arr[left]] = false;
            left++;
            ans -= n - right;
        }else{
            visited[arr[right]] = true;
            right++;
        }
    }

    cout << ans;

    return 0;
}

