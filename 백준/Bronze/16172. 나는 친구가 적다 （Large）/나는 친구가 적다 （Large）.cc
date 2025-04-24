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

vi getPi(const string &pattern){
    int m = pattern.size();
    vi pi(m,0);
    int j = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j]){
            j = pi[j-1];
        }
        if (pattern[i] == pattern[j]){
            pi[i] = ++j;
        }
    }
    return pi;
}

bool kmp(const string &s, const string &pattern){
    vi pi = getPi(pattern);
    int n = s.size(), m = pattern.size();
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && s[i] != pattern[j]){
            j = pi[j-1];
        }
        if (s[i] == pattern[j]){
            if (j == m-1){
                return true;
            }else{
                j++;
            }
        }
    }
    return false;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    string a, b;
    cin >> a >> b;
    string t = "";
    for (int i = 0; i < a.length(); i++) {
        if (a[i] >= '0' && a[i] <= '9'){
            continue;
        }
        t+=a[i];
    }
    cout << (kmp(t,b));


    return 0;
}

