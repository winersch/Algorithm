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


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    cin.ignore();
    for(int k = 1; k <= t; k++){
        string s;
        getline(cin, s);
        int cnt[26] = {};

        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z'){
                cnt[s[i] - 'a']++;
            }
            else if (s[i] >= 'A' && s[i] <= 'Z'){
                cnt[s[i] - 'A']++;
            }
        }
        int ans = 3;
        for (int i = 0; i < 26; i++) {
            ans = min(ans, cnt[i]);
        }

        cout << "Case " << k << ": ";
        if (ans == 3){
            cout << "Triple pangram!!!\n";
        }else if (ans == 2){
            cout << "Double pangram!!\n";
        }else if (ans == 1){
            cout << "Pangram!\n";
        }else{
            cout << "Not a pangram\n";
        }

    }

    return 0;
}
