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

string s, t;
map<string, bool> visited;
bool selected[21];
vs ans;

void find(){
    if (s.length() == t.length()){
        if (visited[t] == false){
            visited[t] = true;
            ans.push_back(t);
        }
        return;
    }
    char prev = 0;
    for (int i = 0; i < s.length(); i++) {
        if (selected[i] != true && s[i] != prev){
            selected[i] = true;
            t.push_back(s[i]);
            find();
            selected[i] = false;
            t.pop_back();
            prev = s[i];
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    while(n--){
        visited.clear();
        ans.clear();
        cin >> s;
        std::sort(s.begin(), s.end());
        find();
        for(string& st : ans){
            cout << st << "\n";
        }
    }

    return 0;
}
