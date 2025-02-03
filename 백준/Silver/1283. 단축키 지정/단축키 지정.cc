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

map<char, bool> selected;
vector<pair<string,int>> v;



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        int idx = -1;
        bool select = false;
        if (!selected[tolower(s[0])]){
            idx = 0;
            v.push_back({s, 0});
            selected[tolower(s[0])] = true;
            select = true;
        }
        if (!select){
            for (int j = 1; j < s.length(); j++) {
                if (s[j-1] == ' ' && !selected[tolower(s[j])]){
                    idx = j;
                    selected[tolower(s[j])] = true;
                    select = true;
                    break;
                }
            }
        }
        if (!select){
            for (int j = 1; j < s.length(); j++) {
                if (s[j] == ' '){
                    continue;
                }
                if (!selected[tolower(s[j])]){
                    selected[tolower(s[j])] = true;
                    select = true;
                    idx = j;
                    break;
                }
            }
        }
        if (!select){
            cout << s << "\n";
        }else{
            for (int j = 0; j < s.length(); j++) {
                if (j == idx){
                    cout << "[" << s[j] << "]";
                }else{
                    cout << s[j];
                }
            }
            cout << "\n";
        }
    }



    return 0;
}

