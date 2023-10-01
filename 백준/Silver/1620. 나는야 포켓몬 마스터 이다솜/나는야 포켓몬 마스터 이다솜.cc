#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <map>

using namespace std;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    map<string, int> name;
    map<int, string> num;


    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        name.insert({s, i});
        num.insert({i,s});
    }
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (s[0] >= '0' && s[0] <= '9'){
            cout << num.find(stoi(s))->second << "\n";
        }else{
            cout << name.find(s)->second << "\n";
        }
    }

    return 0;

}