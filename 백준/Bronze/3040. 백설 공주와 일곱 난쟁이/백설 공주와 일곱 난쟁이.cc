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

int a[9];
bool ans;

void find(int idx, int sum, int cnt){
    if (cnt == 7 && sum == 100){
        ans = true;
        return;
    }
    for (int i = idx; i < 9; i++) {
        find(i+1,sum + a[i], cnt+1);
        if (ans){
            cout << a[i] << "\n";
            return;
        }
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 9; i++) {
        cin >> a[i];
    }
    find(0,0,0);


    return 0;
}