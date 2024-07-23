#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

#define pii pair<int,int>

int n, k, ans, checked;
int word[51];


void dfs(int depth, int idx) {
    if (depth == k) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if ((word[i] & checked) == word[i]) {
                cnt++;
            }
        }
        ans = max(ans, cnt);
        return;
    }

    for (int i = idx; i < 26; i++) {
        if ((checked & (1 << i)) == 0) {
            checked |= (1 << i);
            dfs(depth + 1, i);
            checked &= ~(1 << i);
        }
    }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            word[i] |= 1 << (s[j] - 'a');
        }
    }

    if (k < 5) {
        cout << 0;
        return 0;
    }
    if (k == 26){
        cout << n;
        return 0;
    }
    k -= 5;
    checked |= 1 << ('a' - 'a');
    checked |= 1 << ('n' - 'a');
    checked |= 1 << ('t' - 'a');
    checked |= 1 << ('i' - 'a');
    checked |= 1 << ('c' - 'a');


    dfs(0, 0);

    cout << ans;

    return 0;
}