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

int n;
bool sel[11];
vector<char> v;
vector<string> ans;

void find(string s){
    int idx = s.length();
    if (idx == n+1){
        ans.push_back(s);
        return;
    }
    for (int i = 0; i <= 9; i++) {
        if (!sel[i]){
            sel[i] = true;
            if (idx == 0){
                find(s + to_string(i));
            }else if (v[idx-1] == '<' && s.back() - '0' < i){
                find(s + to_string(i));
            }else if (v[idx-1] == '>' && s.back() - '0' > i){
                find(s + to_string(i));
            }
            sel[i] = false;
        }
    }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    find("");
    std::sort(ans.begin(), ans.end());
    cout << ans.back() << "\n" << ans.front();

    return 0;
}

