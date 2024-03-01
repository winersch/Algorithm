#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>


#define inf 0x3f3f3f3f
#define mod 1000000000
#define ll long long
using namespace std;

map<string,int> m;
vector<string> v;
int n, mx;
string ans;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        m[s]++;
        if (m[s] == 1){
            v.push_back(s);
        }
    }

    std::sort(v.begin(), v.end());

    for(string s : v){
        if (m[s] > mx){
            ans = s;
            mx = m[s];
        }
    }

    cout << ans;

    return 0;
}
