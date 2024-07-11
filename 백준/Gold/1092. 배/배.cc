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

using namespace std;

int n, m, ans;
vector<int> crane;
vector<int> box;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        crane.push_back(a);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        box.push_back(a);
    }

    std::sort(box.begin(), box.end());

    while (ans <= 10000) {
        if (box.empty()){
            break;
        }
        for (int i = 0; i < n; i++) {
            int curr = crane[i];
            int idx = lower_bound(box.begin(), box.end(), curr+1) - box.begin() - 1;
            if (idx >= 0){
                box.erase(box.begin() + idx);
            }
        }
        ans++;
    }
    if (ans > 10000){
        cout << -1;
    }else{
        cout << ans;
    }
    return 0;
}