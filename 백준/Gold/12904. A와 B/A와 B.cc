#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>


#define inf 0x3f3f3f3f
#define mod 1000000007
#define ll long long
using namespace std;

string s,t;



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> s >> t;

    while(t.length() > s.length()){
        if (t[t.length()-1] == 'B'){
            t = t.substr(0,t.length()-1);
            std::reverse(t.begin(), t.end());
        }else{
            t = t.substr(0,t.length()-1);
        }
    }
    if (s == t){
        cout << 1;
    }else{
        cout << 0;
    }


}