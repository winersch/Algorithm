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

int n, ans;
string s;
vi al;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> s;
    al.resize(26);
    for (int i = 0; i < s.length(); i++) {
        al[s[i]-'A']++;
    }
    for (int i = 0; i < n - 1; i++) {
        string t;
        cin >> t;
        vi tmp;
        tmp = al;
        int cnt = 0;
        for (int j = 0; j < t.length(); j++) {
            if (tmp[t[j]-'A']){
                tmp[t[j]-'A']--;
                cnt++;
            }
        }

        if (t.length() == s.length() && (cnt == s.length() || cnt == s.length()-1)){
            ans++;
        } else if (t.length() == s.length()-1 && cnt == s.length()-1){
            ans++;
        }else if (t.length() == s.length()+1 && cnt == s.length()){
            ans++;
        }
    }

    cout << ans;
    return 0;
}

