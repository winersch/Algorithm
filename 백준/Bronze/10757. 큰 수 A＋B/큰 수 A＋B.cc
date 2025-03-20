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
#include <list>
#include <unordered_set>

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

    string a, b, ans;
    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if (a.length() < b.length()){
        swap(a,b);
    }
    int idx = 0;
    int carry = 0;
    while(idx < b.length()){
        int x, y;
        x = a[idx] - '0';
        y = b[idx] - '0';
        int tmp = x+y + carry;
        carry = tmp / 10;
        ans.push_back((tmp % 10) + '0');
        idx++;
    }
    while(idx < a.length()){
        int tmp = (a[idx] - '0') + carry;
        carry = tmp / 10;
        ans.push_back((tmp % 10) + '0');
        idx++;
    }
    if (carry){
        ans.push_back(carry + '0');
    }
    std::reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}

