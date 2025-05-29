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
#include <sstream>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int cnt[101];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y;
        for (int j = x; j < y; j++) {
            cnt[j]++;
        }
    }
    int ans = 0;
    for (int i = 1; i < 100; i++) {
        if (cnt[i] == 1){
            ans += a;
        }else if (cnt[i] == 2){
            ans += b * 2;
        }else if (cnt[i] == 3){
            ans += c * 3;
        }
    }
    cout << ans;
    return 0;
}
