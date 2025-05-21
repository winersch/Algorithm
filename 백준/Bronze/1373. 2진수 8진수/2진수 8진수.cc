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

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    string s;
    cin >> s;
    std::reverse(s.begin(), s.end());
    string ans = "";
    for (int i = 0; i < s.length(); i+=3) {
        int t = 0;
        if (s[i] == '1'){
            t += 1;
        }
        if (s[i+1] == '1'){
            t += 2;
        }
        if (s[i+2] == '1' ){
            t += 4;
        }
        ans.push_back(t + '0');
    }
    std::reverse(ans.begin(), ans.end());
    cout << ans;

    return 0;
}
