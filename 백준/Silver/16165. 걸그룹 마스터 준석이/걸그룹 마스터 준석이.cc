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

int n, m;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    map<string, vector<string>> team;
    map<string, string> member;
    for (int i = 0; i < n; i++) {
        string name;
        int cnt;
        cin >> name >> cnt;
        for (int j = 0; j < cnt; j++) {
            string s;
            cin >> s;
            team[name].push_back(s);
            member[s] = name;
        }
        std::sort(team[name].begin(), team[name].end());
    }
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        int a;
        cin >> a;
        if (a == 0){
            for(auto at : team[s]){
                cout << at << "\n";
            }
        }else{
            cout << member[s] << "\n";
        }
    }


    return 0;
}
