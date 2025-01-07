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

int n, l, ans;
vector<pii> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }

    std::sort(v.begin(), v.end());
    int last = 0;
    for (int i = 0; i < v.size(); i++) {
        int start = v[i].first;
        int end = v[i].second;
        if (start < last){
            start = last;
        }
        while(start < end){
            ans++;
            start += l;
        }
        last = max(last, start);
    }

    cout << ans;


    return 0;
}