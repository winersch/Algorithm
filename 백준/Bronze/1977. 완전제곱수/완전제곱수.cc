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
#include <list>
#include <unordered_set>
#include <sstream>
#include <ctime>
#include <iomanip>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>
#define vs vector<string>

using namespace std;

bool isPerfectSquare(int n)
{
    int i = n;
    while (i * i > n) {
        i = (i + n / i) / 2;
    }
    return i * i == n;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int sum = 0, low = inf;
    for (int i = n; i <= m; i++) {
        if (isPerfectSquare(i)){
            low = min(low, i);
            sum+=i;
        }
    }
    if (low == inf){
        cout << -1;
        return 0;
    }
    cout << sum << "\n" << low;
    return 0;
}