#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>


#define inf 0x3f3f3f3f
#define mod 1234567
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>

using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    std::sort(v.begin(), v.end());
    cout << v[0] << " " << v[1] << " " << v[2];

    return 0;

}