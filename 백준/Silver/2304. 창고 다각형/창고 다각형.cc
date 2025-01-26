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

int n, ans;
int arr[1001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    int max_pos, max_height = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr[a] = b;
        if (b > max_height){
            max_pos = a;
            max_height = b;
        }
    }
    int t = 0;
    for (int i = 0; i < max_pos; i++) {
        t = max(t, arr[i]);
        ans += t;
    }
    t = 0;
    for (int i = 1000; i > max_pos; i--) {
        t = max(t, arr[i]);
        ans += t;
    }

    cout << ans + max_height;

    return 0;
}