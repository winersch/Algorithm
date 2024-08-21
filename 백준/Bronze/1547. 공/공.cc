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

int n;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    int curr = 1;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a == curr){
            curr = b;
        }else if(b == curr){
            curr = a;
        }
    }

    cout << curr;

    return 0;
}