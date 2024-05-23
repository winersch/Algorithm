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

int h, w, ans;
vector<int> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> h >> w;
    v.resize(w+1);
    for (int i = 0; i < w; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < w; i++) {
        int right = 0, left = 0;
        for (int j = i+1; j < w; j++) {
            right = max(right, v[j]);
        }
        for (int j = i-1; j >= 0; j--) {
            left = max(left, v[j]);
        }
        if (min(right, left) - v[i] > 0){
            ans += min(right, left) - v[i];
        }
    }
    cout << ans;


    return 0;
}