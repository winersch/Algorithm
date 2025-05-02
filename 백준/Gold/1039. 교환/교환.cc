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

int n, m;
string ans = "";
unordered_set<string> visited[11];

void find(int depth, string s){
    if (visited[depth].count(s)) return;
    visited[depth].insert(s);
    if (depth == m){
        ans = max(ans , s);
        return;
    }
    for (int i = 0; i < s.length(); i++) {
        for (int j = i+1; j < s.length(); j++) {
            string t = s;
            swap(t[i], t[j]);
            if (t[0] == '0'){
                continue;
            }
            find(depth+1, t);
        }
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    string s = to_string(n);
    find(0, s);
    if (ans.empty()){
        cout << -1;
    }else{
        cout << ans;
    }



    return 0;
}

