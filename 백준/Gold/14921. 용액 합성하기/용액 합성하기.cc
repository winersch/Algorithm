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

int n;
vi v;



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int left = 0, right = n-1;
    int ans = inf;
    while(left < right){
        int t = v[left] + v[right];
        if (abs(t) < abs(ans)){
            ans = t;
        }
        if (t == 0){
            break;
        }
        if (t <= 0){
            left++;
        }else{
            right--;
        }
    }
    cout << ans;
}

