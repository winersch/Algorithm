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


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n, k;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    cin >> n >> k;
    if (n <= k){
        cout << 0;
        return 0;
    }
    int ans = 0;
    while(true){
        int cnt = 0;
        int tmp = n;
        while(tmp > 0){
            if (tmp % 2 == 0){
                tmp /= 2;
            }else{
                tmp /= 2;
                cnt++;
            }
        }
        if (k >= cnt){
            break;
        }
        n++;
        ans++;
    }
    cout << ans;




    return 0;
}