#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>


using namespace std;



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    map<string,string> pass;
    for (int i = 0; i < n; i++) {
        string s1,s2;
        cin >> s1 >> s2 ;
        pass.insert({s1,s2});
    }
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        cout << pass.find(s)->second << "\n";
    }

    return 0;
}