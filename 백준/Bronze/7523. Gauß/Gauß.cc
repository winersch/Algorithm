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

    int t;
    cin >> t;
    for(int x = 1; x <= t; x++){
        int a, b;
        cin >> a >> b;
        ll ans = 1LL * (b-a+1) * (a+b) / 2;
        cout << "Scenario #" << x << ":\n";
        cout << ans << "\n\n";

    }


    return 0;
}
