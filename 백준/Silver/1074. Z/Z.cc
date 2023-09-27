#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

int n, r, c;
int ans;


void z(int x, int y, int size) {

    if (x == c && y == r) {
        cout << ans << "\n";
        return;
    }

    if (r < y + size && r >= y && c < x + size && c >= x) {
        z(x, y, size / 2);
        z(x + size / 2, y, size / 2);
        z(x, y + size / 2, size / 2);
        z(x + size / 2, y + size / 2, size / 2);
    }else{
        ans += size*size;
    }


}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> r >> c;
    z(0,0,(1<<n));
    return 0;

}