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

struct country{
    int a, b, c;

    bool operator==(const country& other) const{
        return a == other.a && b == other.b && c == other.c;
    }
    bool operator!=(const country& other) const{
        return a != other.a || b != other.b || c != other.c;
    }
};

vector<pair<int,country>> v;
int n, k;
int cnt[1001];

bool comp(pair<int,country>& a, pair<int,country>& b){
    country ca = a.second;
    country cb = b.second;

    if (ca.a == cb.a){
        if (ca.b == cb.b){
            return ca.c > cb.c;
        }else{
            return ca.b > cb.b;
        }
    } else{
        return ca.a > cb.a;
    }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int m, a, b, c;
        cin >> m >> a >> b >> c;
        v.push_back({m,{a,b,c}});
    }

    std::sort(v.begin(), v.end(), comp);
    int idx = 1, t = 0;
    cnt[0] = 1;
    for (int i = 1; i < v.size(); i++) {
        if (v[i].second != v[i-1].second){
            idx++;
            idx+=t;
            t = 0;
        }else{
            t++;
        }
        cnt[i] = idx;
    }

    for (int i = 0; i < v.size(); i++) {
        if (v[i].first == k){
            cout << cnt[i];
        }
    }

    return 0;
}

