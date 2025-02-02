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
    cin >> s;
    int a = 0, ans = inf;
    for(char c : s){
        if (c == 'a'){
            a++;
        }
    }

    for (int i = 0; i < s.length(); i++) {
        int cnt = a, b = 0;
        for (int j = i; j < i + s.length(); j++) {
            if (cnt == 0){
                break;
            }
            if (s[j % s.length()] == 'b'){
                b++;
                cnt--;
            }else{
                cnt--;
            }
        }
        ans = min(ans, b);
    }



    cout << ans;

    return 0;
}

