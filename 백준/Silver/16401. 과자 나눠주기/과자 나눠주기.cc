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

int n, m;
vi v;

int find(int a){
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        cnt += v[i]/a;
    }
    return cnt;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int low = 1, high = *max_element(v.begin(), v.end()), mid, ans = 0;

    while(low <= high){
        mid = (low + high)/2;
        if (find(mid) >= n){
            ans = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    cout << ans;

}

