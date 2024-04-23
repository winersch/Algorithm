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

using namespace std;



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    double a, b, h;
    cin >> a >> b >> h;

    if (a == b){
        cout << -1;
        return 0;
    }

    if (a > b){
        swap(a,b);
    }

    double t = a*h/(b-a);

    double outer = pow(t + h, 2) + pow(b,2);
    double inner;
    if (a <= 0){
        inner = 0;
    }else{
        inner = pow(t,2) + pow(a,2);
    }
    double ans = (outer - inner) * acos(-1);
    cout.precision(6);
    cout << fixed << ans;

    return 0;
}