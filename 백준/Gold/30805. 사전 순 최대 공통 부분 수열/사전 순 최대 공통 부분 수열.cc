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

int n, m;
vector<pii> v1, v2;

bool comp(pii a, pii b){
    if (a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v1.push_back({a, i});
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        v2.push_back({a, i});
    }

    std::sort(v1.begin(), v1.end(), comp);
    std::sort(v2.begin(), v2.end(), comp);

    int idx1 = 0, idx2 = 0, l1 = 0, l2 = 0;
    vi ans;
    while(idx1 < n && idx2 < m){
        if (v1[idx1].first == v2[idx2].first){
            if (l1 > v1[idx1].second){
                idx1++;
            }else if(l2 > v2[idx2].second){
                idx2++;
            }else{
                l1 = v1[idx1].second;
                l2 = v2[idx2].second;
                ans.push_back(v1[idx1].first);
                idx1++;
                idx2++;
            }
        }else if (v1[idx1].first < v2[idx2].first){
            idx2++;
        }else{
            idx1++;
        }
    }

    cout << ans.size() << "\n";
    for(int a : ans){
        cout << a << " ";
    }

    return 0;
}