#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;




int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, ans=0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        ans += a-1;
    }
    cout << ans+1;
    return 0;
}