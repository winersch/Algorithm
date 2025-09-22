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

void to_lower(string& s){
    for(char &c : s){
        if (c >= 'A' && c <= 'Z'){
            c += 32;
        }
    }
}

bool is_pallindrome(string& s){
    to_lower(s);

    int left = 0, right = s.length()-1;
    while(left < right){
        if (s[left] != s[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t; cin >> t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin,s);
        cout << (is_pallindrome(s) ? "Yes" : "No") << "\n";
    }

    return 0;
}
