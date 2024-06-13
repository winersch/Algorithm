#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>

using namespace std;

int n;
vector<int> v;
vector<int> ans;


int binarySearch(int a) {
    int mid;
    int left = 0, right = ans.size() - 1;
    while (left < right) {
        mid = (left + right) / 2;
        if (ans[mid] < a) {
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
        v.push_back(a);
    }

    ans.push_back(v[0]);

    for (int i = 1; i < n; i++) {
        if (ans.back() < v[i]){
            ans.push_back(v[i]);
        }else{
            int pos = binarySearch(v[i]);
            ans[pos] = v[i];
        }
    }

    cout << ans.size() << "\n";

    return 0;
}