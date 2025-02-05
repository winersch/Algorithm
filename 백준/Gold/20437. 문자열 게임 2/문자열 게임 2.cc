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


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        string s;
        int k;
        cin >> s >> k;

        int a = inf, b = 0;
        vi v[26];
        for (int i = 0; i < s.length(); i++) {
            v[s[i]-'a'].push_back(i);
        }

        for (int i = 0; i < 26; i++) {
            if (v[i].size() >= k){
                for (int j = 0; j <= v[i].size() - k; j++) {
                    a = min(a, v[i][j+k-1] - v[i][j]+1);
                    b = max(b, v[i][j+k-1] - v[i][j]+1);
                }
            }
        }

        if (a == inf || b == 0){
            cout << -1 << "\n";
        }else{
            cout << a << " " << b << "\n";
        }
    }

    return 0;
}

