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
#include <regex>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>
#define vs vector<string>

using namespace std;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int a, b, c;
    int idx = 1;
    while (true) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0){
            break;
        }
        int ans = 0;
        ans += a * (c / b);
        ans += min(a, c%b);
        cout << "Case " << idx << ": " << ans << "\n";
        idx++;
    }


    return 0;
}
