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

int n, k, ans;
int arr[100001];

bool find(int a){
    int cnt = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum >= a){
            cnt++;
            sum = 0;
        }
    }
    return cnt >= k;
}

void binary_search(){
    int left = 0;
    int right = n * 20;
    while(left <= right){
        int mid = (left + right) / 2;
        if (find(mid)){
            ans = mid;
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    binary_search();
    cout << ans;

    return 0;
}