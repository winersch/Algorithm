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
string s[20001];
map<string, int> m;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < s[i].length()+1; j++) {
            string t = s[i].substr(0,j);
            m[t]++;
        }
    }

    int mlen = -1;
    string head, s1, s2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s[i].length()+1; j++) {
            string t = s[i].substr(0,j);
            if (m[t] >= 2 && j > mlen){
                mlen = j;
                head = t;
                s1 = s[i];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == s1){
            continue;
        }
        string t = s[i].substr(0,mlen);
        if (t == head){
            s2 = s[i];
            break;
        }
    }

    cout << s1 << "\n" << s2;
    return 0;
}

