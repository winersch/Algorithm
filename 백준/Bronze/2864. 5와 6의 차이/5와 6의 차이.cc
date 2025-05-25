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

    string s1, s2;
    cin >> s1 >> s2;
    int a = stoi(s1);
    int b = stoi(s2);
    int ans = a + b;
    std::reverse(s1.begin(), s1.end());
    std::reverse(s2.begin(), s2.end());
    int mx = ans, mn = ans;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] == '5'){
            mx += pow(10 , i);
        }
        if (s1[i] == '6'){
            mn -= pow(10, i);
        }
    }
    for (int i = 0; i < s2.length(); i++) {
        if (s2[i] == '5'){
            mx += pow(10 , i);
        }
        if (s2[i] == '6'){
            mn -= pow(10, i);
        }
    }

    cout << mn << " " << mx;
    return 0;
}
