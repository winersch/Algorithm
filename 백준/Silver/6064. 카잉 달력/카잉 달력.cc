#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>


using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        int result = -1;
        int maxi = lcm(m,n);
        for (int j = x; j <= maxi; j+=m) {
            int ny = j % n;
            if (ny == 0){
                ny = n;
            }
            if (ny == y){
                result = j;
                break;
            }
        }
        cout << result << "\n";
    }


    return 0;
}