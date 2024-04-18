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
#define mod 10007
#define ll long long
using namespace std;




int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, a, b;
    cin >> n >> a >> b;
    int cnt = 1;
    while(n > 0){
        a++;
        a/=2;
        b++;
        b/=2;
        if (a == b){
            cout << cnt;
            break;
        }
        n /= 2;
        cnt++;
    }


    return 0;
}