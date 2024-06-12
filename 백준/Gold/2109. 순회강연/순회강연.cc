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


int n, ans;
vector<pii> v;
int plan[10001];


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    std::sort(v.begin(), v.end(), greater());
    for (int i = 0; i < n; i++) {
        for (int j = v[i].second; j > 0; j--) {
            if (plan[j] == 0){
                plan[j] = v[i].first;
                break;
            }
        }
    }
    for (int i = 1; i <= 10000; i++) {
        ans += plan[i];
    }
    cout << ans;
    return 0;
}