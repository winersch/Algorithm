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

vector<string> ans;
int n;

bool calc(string s){
    int sum = 0;
    int t = 0;
    bool add = true;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c >= '0' && c <= '9'){
            t = t*10 + (c - '0');
            if (i == s.length()-1){
                if (add){
                    sum += t;
                }else{
                    sum -= t;
                }
            }
        }
        if (c == '+' || c == '-'){
            if (add){
                sum += t;
            }else{
                sum -= t;
            }
            t = 0;
            if (c == '+'){
                add = true;
            }else{
                add = false;
            }
        }
    }

    return sum == 0;
}

void solve(int now, string s){
    if (now == n){
        if (calc(s)){
            cout << s << "\n";
        }
        return;
    }

    solve(now +1, s + " " + to_string(now+1));
    solve(now +1, s + "+" + to_string(now+1));
    solve(now +1, s + "-" + to_string(now+1));

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){

        cin >> n;
        ans.clear();
        solve(1,"1");

        cout << "\n";

    }


    return 0;
}

