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

    vi v(3);
    for (int i = 0; i < 3; i++) {
        cin >> v[i];
    }

    std::sort(v.begin(), v.end());
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        cout << v[s[i] - 'A'] << " ";
    }
    return 0;
}

