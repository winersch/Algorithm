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

    int n, m, cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        if (n%i == 0){
            cnt++;
        }
        if (cnt == m){
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}