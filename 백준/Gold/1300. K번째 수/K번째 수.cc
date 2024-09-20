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

int n, k;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;

    int low = 1, high = k, mid;

    while(low < high){
        mid = (low + high)/2;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += min(n, mid/i);
        }

        if (cnt < k){
            low = mid+1;
        }else{
            high = mid;
        }
    }

    cout << high;

    return 0;
}