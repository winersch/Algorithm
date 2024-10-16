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

    vi v;
    for (int i = 0; i < 4; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    std::sort(v.begin(), v.end(), greater<>());
    int a, b;
    cin >> a >> b;
    cout << v[0] + v[1] + v[2] + max(a,b);


}