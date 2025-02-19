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

int n;
map<string,bool> m;
vector<string> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    char c;
    cin >> c;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!m[v[i]]){
            m[v[i]] = true;
            cnt++;
        }
    }
    int t = 0;
    if (c == 'Y'){
        t = 1;
    }
    if (c == 'F'){
        t = 2;
    }
    if (c == 'O'){
        t = 3;
    }

    cout << cnt / t;

    return 0;
}

