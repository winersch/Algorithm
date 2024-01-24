#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

long long num[55];
long long a, b;

long long find(long long x){
    long long tmp = x & 1;

    for (int i = 54; i > 0; i--) {
        if (x & (1LL << i)){
            tmp += num[i-1] + (x - (1LL << i) +1);
            x -= 1LL << i;
        }
    }

    return tmp;
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> a >> b;

    num[0] = 1;
    for (int i = 1; i < 55; i++) {
        num[i] = 2 * num[i-1] + (1LL << i);
    }

    cout << find(b) - find(a-1);

    return 0;
}