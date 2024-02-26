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



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    vector<int> v;
    bool isten = false;
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0' && !isten){
            isten = true;
        }
        v.push_back(s[i]-'0');
        sum += s[i]-'0';
    }
    if (sum %3 != 0){
        cout << -1;
        return 0;
    }
    std::sort(v.begin(), v.end(), greater<int>());
    if (!isten){
        cout << -1;
        return 0;
    }
    for(int i : v){
        cout << i;
    }




    return 0;
}
