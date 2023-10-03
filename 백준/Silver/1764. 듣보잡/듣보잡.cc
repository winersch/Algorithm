#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <map>

using namespace std;


int n, m;
vector<string> notHear;
map<string, int> notSee;
vector<string> v;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        notHear.push_back(s);
    }

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        notSee.insert({s, i});
    }

    for (int i = 0; i < n; i++) {
        if (notSee.find(notHear[i]) != notSee.end()) {
            v.push_back(notHear[i]);
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }

    return 0;

}