#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>


#define inf 0x3f3f3f3f
#define mod 1000000000
using namespace std;

int n,m;
int basket[101];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a,b,c;
        cin >> a >>b >>c;
        for (int j = a; j <= b; j++) {
            basket[j] = c;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << basket[i] << " ";
    }
    return 0;
}
