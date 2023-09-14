#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
int prime[1000001];

int main() {

    cin >> n >> m;
    fill_n(prime, 1000001, 1);
    prime[0] = prime[1] = 0;
    for (int i = 2; i * i <= m; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= m; j += i) {
                prime[j] = 0;
            }
        }
    }

    for (int i = n; i <= m; i++) {
        if (prime[i]) {
            cout << i << "\n";
        }
    }

    return 0;
}
