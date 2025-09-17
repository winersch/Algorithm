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
#include <ctime>
#include <iomanip>
#include <regex>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>
#define vs vector<string>

using namespace std;



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    string s;
    while(true){
        getline(cin, s);
        set<char> ch;
        if (s == "#"){
            break;
        }
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z'){
                ch.insert(s[i]);
            }
            if (s[i] >= 'A' && s[i] <= 'Z'){
                ch.insert(s[i] + 32);
            }
        }
        cout << ch.size() << "\n";
    }


    return 0;
}
