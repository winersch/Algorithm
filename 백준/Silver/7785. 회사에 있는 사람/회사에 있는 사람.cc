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

map<string, bool> m;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        if (s2 == "enter"){
            m[s1] = true;
        }else{
            m[s1] = false;
        }
    }
    vector<string> v;
    for(auto [x, y] : m){
        if (y){
            v.push_back(x);
        }
    }
    std::reverse(v.begin(), v.end());
    for(auto x : v){
        cout << x << "\n";
    }



    return 0;
}
