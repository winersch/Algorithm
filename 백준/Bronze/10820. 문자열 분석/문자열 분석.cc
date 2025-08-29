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
    while(getline(cin, s)){
        tuple<int,int,int,int> t = {0,0,0,0};
        for (int i = 0; i < s.length(); i++) {
            if (s[i] <= 'z' && s[i] >= 'a'){
                get<0>(t)++;
            }
            if (s[i] <= 'Z' && s[i] >= 'A'){
                get<1>(t)++;
            }
            if (s[i] <= '9' && s[i] >= '0'){
                get<2>(t)++;
            }
            if (s[i] == ' '){
                get<3>(t)++;
            }
        }
        cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t) << "\n";
    }


    return 0;
}