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

    string s;
    int ans = 10;
    cin >> s;
    for (int i = 0; i < s.length()-1; i++) {
        if (s[i] == s[i+1]){
            ans += 5;
        }else{
            ans += 10;
        }
    }
    cout << ans;
    return 0;
}