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
#include <ctime>
#include <iomanip>
#include <regex>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>
#define vs vector<string>

using namespace std;

map<int,int> m;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n,p;
    cin >> n >> p;

    int t = n;

    while(true){
        m[t]++;
        if (m[t] == 3){
            break;
        }
        t *= n;
        t %= p;
    }
    int ans = 0;
    for(const auto [a, b] : m){
        if (b >= 2){
            ans++;
        }
    }
    cout << ans;

    return 0;
}