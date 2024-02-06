#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>

#define inf 0x3f3f3f;
using namespace std;

int n, m;
int input[41];
map<int,int> total;
long long ans;

void left(int a, int sum){
    if (a == n/2){
        total[sum]++;
        return;
    }
    left(a+1,sum);
    left(a+1, sum + input[a]);

}

void right(int a, int sum){
    if (a == n){
        ans += total[m-sum];
        return;
    }
    right(a+1, sum);
    right(a+1, sum + input[a]);
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    left(0,0);
    right(n/2,0);
    if (m == 0){
        ans--;
    }
    cout << ans;

    return 0;
}
