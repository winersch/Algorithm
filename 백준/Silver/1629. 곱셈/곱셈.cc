#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>


using namespace std;

long long int calc(int a, int b, int c) {
    if (b == 1) {
        return a % c;
    }
    long long int tmp = calc(a, b / 2, c);
    tmp = tmp * tmp % c;
    if (b % 2 == 0) {
        return tmp % c;
    }
    return tmp * a % c;

}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int a, b, c;
    long long int ans = 0;
    cin >> a >> b >> c;

    cout << calc(a,b,c);

    return 0;
}