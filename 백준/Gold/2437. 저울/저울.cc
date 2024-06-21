#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>

using namespace std;


int n;
vector<int> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    std::sort(v.begin(), v.end());
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (v[i] > ans){
            break;
        }
        ans += v[i];
    }

    cout << ans;
    return 0;
}