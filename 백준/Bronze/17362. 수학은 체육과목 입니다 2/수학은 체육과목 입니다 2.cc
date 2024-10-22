#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
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


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    if (n <= 5) cout << n << '\n';
    else {
        if ((n - 5) / 4 % 2 == 0)
            cout << 5 - (n - 5) % 4 << '\n';
        else
            cout << 1 + (n - 5) % 4 << '\n';
    }

    return 0;
}