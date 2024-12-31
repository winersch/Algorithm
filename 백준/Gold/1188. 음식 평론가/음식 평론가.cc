#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

#define inf 0x3f3f3f
#define pii pair<int,int>
#define ll long long

int n, m;

int gcd(int a, int b){
    int t = a % b;
    if (t == 0){
        return b;
    }
    return gcd(b,t);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    cout << m - gcd(n,m);


    return 0;
}