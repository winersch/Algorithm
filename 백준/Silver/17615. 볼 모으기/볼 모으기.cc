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

int n, b, ans = inf;
string s;

void find(char c){
    int cnt = 0;
    bool ch = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != c){
            ch = true;
        }else if (ch && s[i] == c){
            cnt++;
        }
    }
    ans = min(ans, cnt);
    ch = false;
    cnt = 0;
    for (int i = s.size()-1; i >= 0; i--) {
        if (s[i] != c){
            ch = true;
        }else if(ch && s[i] == c){
            cnt++;
        }
    }
    ans = min(ans, cnt);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    cin >> s;
    find('R');
    find('B');
    cout << ans;

    return 0;
}