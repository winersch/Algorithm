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

using namespace std;

int n, ans;
vector<int> lis, v;


int binarySearch(int id) {
    int mid;
    int left = 0, right = lis.size() - 1;
    while (left < right) {
        mid = (left + right) / 2;
        if (lis[mid] < id) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a-1);
    }
    lis.push_back(v[0]);
    for (int i = 0; i < n; i++) {
        if (lis.back() < v[i]){
            lis.push_back(v[i]);
        }else{
            int pos = binarySearch(v[i]);
            lis[pos] = v[i];
        }
    }

    cout << n - lis.size();

    return 0;
}