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

    int n, m;
    cin >> n >> m;
    vi v(n);
    iota(v.begin(), v.end(), 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        std::reverse(v.begin()+a-1, v.begin()+b);
    }
    for (int i = 0; i < n; ++i) {
        std::cout << v[i] << " ";
    }
    return 0;
}