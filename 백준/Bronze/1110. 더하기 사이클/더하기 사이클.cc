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

    int n;
    cin >> n;
    int t = 0;
    t += n/10;
    t += n%10;
    t = (n%10)*10 + t%10;
    int cnt = 1;
    while(t != n){
        int tmp = 0;
        tmp += t/10;
        tmp += t%10;
        tmp = (t%10)*10 + tmp%10;
        t = tmp;
        cnt++;
    }
    cout << cnt;

    return 0;
}