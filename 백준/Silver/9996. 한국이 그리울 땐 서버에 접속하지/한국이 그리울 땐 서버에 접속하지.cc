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

    int n;
    cin >> n;
    string t;
    cin >> t;
    int pos = t.find('*');
    string reg = "^" + t.substr(0, pos) + ".*" + t.substr(pos + 1) + "$";
    regex re(reg);

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (regex_match(s, re)){
            cout << "DA\n";
        }else{
            cout << "NE\n";
        }
    }


    return 0;
}