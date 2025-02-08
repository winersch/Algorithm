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
vector<pair<int,string>> v;
int arr[100001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        int a;
        cin >> s >> a;
        v.push_back({a,s});
        arr[i] = a;
    }

    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        auto it = lower_bound(v.begin(), v.end(), make_pair(a , ""), [](const pair<int,string>& p1, const pair<int,string>& p2){
            return p1.first < p2.first;
        });
        cout << it->second << "\n";
    }

    return 0;
}

