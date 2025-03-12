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

string s;
int ans, z, o;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> s;

    int idx = 0;
    while(idx < s.length()){
        char now = s[idx];
        while(idx < s.length() && s[idx] == now){
            idx++;
        }
        if (now == '0'){
            z++;
        }else{
            o++;
        }
    }

    cout << min(z,o);

    return 0;
}

