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
#include <set>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n;
int arr[21];
bool check[2000001];

void find(int sum, int idx){
    check[sum] = true;
    if (idx == n){
        return;
    }
    find(sum, idx+1);
    find(sum+arr[idx], idx+1);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    find(0,0);

    for (int i = 1; i < 2000001; i++) {
        if (!check[i]){
            cout << i;
            break;
        }
    }

    return 0;
}