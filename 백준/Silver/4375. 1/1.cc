#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>


#define inf 0x3f3f3f3f
#define mod 1000000000
#define ll long long
using namespace std;


int main() {
//    cin.tie(NULL);
//    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, ans ,t;
    while (cin >> n) {
        ans = 1;
        t = 1;

        while(true){
            if (ans % n ==0){
                break;
            }
            else{
                t++;
                ans = ans*10+1;
                ans %= n;
            }
        }
        cout << t << "\n";
    }

    return 0;
}
