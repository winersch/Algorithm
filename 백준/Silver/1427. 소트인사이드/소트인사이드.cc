#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>


using namespace std;

int ans[20];

bool compare(int a, int b){
    return a>b;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        ans[i] = s[i] - '0';
    }
    sort(ans, ans + s.size(), compare);
    for (int i = 0; i < s.size(); i++) {
        cout << ans[i];
    }
    return 0;
}