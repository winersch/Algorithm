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

    int sum = 0, m = inf;
    for (int i = 0; i < 7; i++) {
        int a;
        cin >> a;
        if (a%2 == 1){
            m = min(m, a);
            sum+=a;
        }
    }
    if (m == inf){
        cout << -1;
    }else{
        cout << sum << "\n" << m;
    }


    return 0;
}