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

string s;
int ans;

bool is_palindrom(string &str){
    for (int i = 0; i < str.length()/2; i++) {
        if (str[i] != str[str.length()-i-1]){
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> s;

    int len = s.length();
    for (int i = 0; i < len; i++) {
        string t = s + string(s.begin(), s.begin() + i);
        reverse(t.begin() + len, t.end());
        if (is_palindrom(t)){
            cout << t.length();
            return 0;
        }
    }


    cout << ans;


    return 0;
}

