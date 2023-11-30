#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>
#include <stack>


using namespace std;

int n;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        int ans = 1, cnt = 1;
        cin >> a >> b;
        for (int j = b; j > b-a; j--) {
            ans *= j;
            ans /= cnt++;
        }
        cout << ans << "\n";
    }

    return 0;
}