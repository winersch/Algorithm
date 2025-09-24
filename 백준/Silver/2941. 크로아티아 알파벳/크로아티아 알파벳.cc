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


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int idx = 0, ans = 0;
    while (idx < s.length()) {
        string st = s.substr(idx, 2);

        if (st == "dz" && s[idx+2] == '=') {
            idx += 3;
            ans++;
        } else if (st == "c=" || st == "c-" || st == "d-" || st == "s=" || st == "z=") {
            idx += 2;
            ans++;
        } else if (st == "lj" || st == "nj") {
            idx += 2;
            ans++;
        } else {
            idx++;
            ans++;
        }
    }
    cout << ans;
    return 0;
}
