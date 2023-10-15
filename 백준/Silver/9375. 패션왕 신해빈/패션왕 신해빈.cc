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

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        std::map<string, int> m;
        for (int j = 0; j < a; j++) {
            string s;
            cin >> s >> s;
            if (m.find(s) == m.end()) {
                m.insert({s, 1});
            } else {
                m[s]++;
            }
        }
        int ans = 1;
        for(auto i : m){
            ans *= (i.second+1);
        }
        ans -=1;
        cout << ans << "\n";
    }


    return 0;
}