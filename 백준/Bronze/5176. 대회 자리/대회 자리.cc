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
#include <list>
#include <unordered_set>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

bool seat[501];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int k;
    cin >> k;
    while(k--){
        int p, m, ans = 0;
        cin >> p >> m;
        memset(seat, false, sizeof(seat));
        for (int i = 0; i < p; i++) {
            int a;
            cin >> a;
            if (!seat[a]){
                seat[a] = true;
            }else{
                ans++;
            }
        }
        cout << ans << "\n";
    }

}

