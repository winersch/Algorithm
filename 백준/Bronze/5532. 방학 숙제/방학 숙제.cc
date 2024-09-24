#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

#define inf 0x3f3f3f
#define pii pair<int,int>

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int l, a, b, c, d;
    cin >> l >> a >> b >> c >> d;
    int ans = 0;
    int a1, a2;
    a1 = a/c;
    a2 = b/d;
    if (a%c != 0){
        a1++;
    }
    if (b%d != 0){
        a2++;
    }
    cout << l - max(a1,a2);
    return 0;
}