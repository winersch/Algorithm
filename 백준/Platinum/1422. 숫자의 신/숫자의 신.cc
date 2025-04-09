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

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int k, n;

bool comp1(string& s1, string& s2){
    if (s1.length() == s2.length()){
        return s1 > s2;
    }
    return s1.length() > s2.length();
}

bool comp2(string& s1, string& s2){
    return s1 + s2 > s2 + s1;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> k >> n;
    vector<string> v(k);
    for (int i = 0; i < k; i++) {
        cin >> v[i];
    }
    std::sort(v.begin(), v.end(), comp1);
    for (int i = 0; i < n - k; i++) {
        v.push_back(v[0]);
    }
    std::sort(v.begin(), v.end(), comp2);
    string ans = "";
    for(string s : v){
        ans += s;
    }

    cout << ans;

    return 0;
}

