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
    int cnt[2] = {0};
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0'){
            cnt[0]++;
        }else{
            cnt[1]++;
        }
    }
    cnt[0] /= 2;
    cnt[1] /= 2;

    while(cnt[0]){
        int idx = s.rfind('0');
        if (idx != string::npos){
            s.erase(idx,1);
            cnt[0]--;
        }
    }

    while(cnt[1]){
        int idx = s.find('1');
        if (idx != string::npos){
            s.erase(idx,1);
            cnt[1]--;
        }
    }
    cout << s;
    return 0;
}

