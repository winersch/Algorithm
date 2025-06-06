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

    set<string> m;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        for (int j = 1; j + i <= s.length(); j++) {
            string t = s.substr(i,j);
            m.insert(t);
        }
    }

    cout << m.size();


    return 0;
}
