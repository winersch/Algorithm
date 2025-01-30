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

int arr[1000001];
int m[1000001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        memset(arr, 0, sizeof(arr));
        memset(m, 0, sizeof(m));
        int n;
        cin >> n;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        m[n-1] = arr[n-1];
        for (int i = n-2; i >= 0; i--) {
            m[i] = max(m[i+1], arr[i]);
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] < m[i]){
                ans += m[i] - arr[i];
            }
        }
        cout << ans << "\n";
    }

    return 0;
}