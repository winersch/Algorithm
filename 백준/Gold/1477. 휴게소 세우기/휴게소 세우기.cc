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

int n, m, l;
vi v, gap;

bool check(int t){
    int cnt = 0;
    for (int a : gap) {
        cnt += (a-1)/t;
    }
    return cnt <= m;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> l;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    v.push_back(0);
    v.push_back(l);
    std::sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); i++) {
        gap.push_back(v[i] - v[i-1]);
    }
    int low = 1, high = l;
    int ans;
    while(low <= high){
        int mid = (low + high)/2;

        if (check(mid)){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }

    cout << ans;

}

