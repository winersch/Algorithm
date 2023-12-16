#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>


using namespace std;


int set[10];
int ans;
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    string s;

    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        set[c-'0']++;
    }
    for (int i = 0; i < 10; i++) {
        if (i == 6 || i == 9){
            continue;
        }
        ans = max(ans, set[i]);
    }
    ans = max(ans, (set[6]+set[9])/2+(set[6]+set[9])%2);
    cout << ans;
    return 0;
}