#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <numeric>
#include <set>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

ll fibo[91];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    fibo[1] = 1;
    for (int i = 2; i <= 90; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    int n;
    cin >> n;
    cout << fibo[n];

    return 0;
}