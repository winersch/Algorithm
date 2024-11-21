#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

#define inf 0x3f3f3f
#define pii pair<int,int>
#define ll long long

int cnt[26];
int n;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int pow = 1;
        for (int j = s.length()-1; j >= 0; j--) {
            cnt[s[j] - 'A'] += pow;
            pow *= 10;
        }
    }
    sort(cnt, cnt+26, greater<>());
    int t = 9, ans = 0;
    for(int a : cnt){
        ans += a*t;
        t--;
    }
    cout << ans;
    return 0;

}